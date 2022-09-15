#pragma once

#include <utility>

template <typename T>
class unique_ptr {
 public:
  unique_ptr() : ptr_(nullptr) {}

  unique_ptr(T *ptr) : ptr_(ptr) {}

  unique_ptr(const unique_ptr &other) = delete;

  unique_ptr(unique_ptr<T> &&other) {
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
  }

  ~unique_ptr() {
    if (ptr_ != nullptr) {
      delete ptr_;
    }
  }

  explicit operator bool() const { return ptr_ != nullptr; }

  unique_ptr &operator=(const unique_ptr &other) = delete;

  unique_ptr &operator=(unique_ptr &&other) {
    if (this == &other) {
      return *this;
    }
    if (ptr_ != nullptr) {
      delete ptr_;
    }
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
    return *this;
  }

  T *Get() const { return ptr_; }

 private:
  T *ptr_;
};
