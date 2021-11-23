#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
    explicit ThreadPool(size_t threads) : stop_(false) {
        for (int i = 0; i < threads; ++i) {
            workers_.emplace_back(
                    [this] {
                        while (true) {
                            std::function<void()> task;

                            {
                                std::unique_lock<std::mutex> lck(this->mtx_);
                                this->cond_.wait(lck, [this]{ return this->stop_ || !this->tasks_.empty(); });
                                if (this->stop_ && this->tasks_.empty()) return;

                                task = std::move(this->tasks_.front());
                                this->tasks_.pop();
                            }

                            task();
                        }

                    });
        }
    }
    virtual ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lck(mtx_);
            stop_ = true;
        }

        cond_.notify_all();

        for (size_t i = 0, thnread_cnt = workers_.size(); i < thnread_cnt; ++i) {
            if (workers_[i].joinable()) workers_[i].join();
        }
    }

    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared< std::packaged_task<return_type()> >(
                std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lck(mtx_);
            if (!stop_) {
                tasks_.emplace([task](){ (*task)(); });
            }
        }

        cond_.notify_one();
        return res;
    }

private:
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;

    std::mutex mtx_;
    std::condition_variable cond_;
    bool stop_;
};