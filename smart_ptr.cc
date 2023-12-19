#include <memory>
template <typename T> class shared_ptr {
public:
  explicit shared_ptr(T *ptr = nullptr) : ptr_(ptr), ref_count_(new int(1)) {}

  ~shared_ptr() { release(); }

  shared_ptr(const shared_ptr<T> &other) {
    ptr_ = other.ptr_;
    ref_count_ = other.ref_count_;
    (*ref_count_)++;
  }

  shared_ptr<T> &operator=(const shared_ptr<T> &other) {
    if (this != &other) {
      release();
      ptr_ = other.ptr_;
      ref_count_ = other.ref_count_;
      (*ref_count_)++;
    }
    return *this;
  }

  T &operator*() const { return *ptr_; }

  T *operator->() const { return ptr_; }

private:
  void release() {
    (*ref_count_)--;
    if (*ref_count_ == 0) {
      delete ptr_;
      delete ref_count_;
    }
  }

  T *ptr_;
  int *ref_count_;
};
