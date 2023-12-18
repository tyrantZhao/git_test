#include <atomic>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <iterator>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool {
public:
  using Task = std::function<void()>;

public:
  virtual ~ThreadPool() {
    { stop_ = true; }

    cond_.notify_all();
    for (auto &t : threads_)
      t.join();
  }
  explicit ThreadPool(int thread_num) : stop_(false) {
    threads_.emplace_back([this] {
      while (true) {
        Task t;
        {
          std::unique_lock<std::mutex> lck(mtx_);
          cond_.wait(lck, [this] { return stop_ || !queue_.empty(); });
          if (stop_ && queue_.empty())
            return;
          t = std::move(queue_.front());
          queue_.pop();
        }
        t();
      }
    });
  }

public:
  template <typename Func, typename... Args>
  void enqueue(Func &&f, Args &&...args) {
    {
      std::lock_guard<std::mutex> lck(mtx_);
      queue_.emplace([=] { f(args...); });
    }
    cond_.notify_one();
  }

private:
  std::atomic<bool> stop_;
  std::vector<std::thread> threads_;
  std::queue<Task> queue_;
  std::mutex mtx_;
  std::condition_variable cond_;
};

void DoTask(int i) { std::cout << "Doing task:" << i << std::endl; }

int main() {
  ThreadPool pool(4);
  for (int i = 0; i < 15; ++i) {
    pool.enqueue(DoTask, i);
  }

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(1s);

  return 0;
}
