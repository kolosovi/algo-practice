#pragma once

#include <vector>

class MyCircularQueue {
 public:
  MyCircularQueue(int k) : size_(k), len_(0), start_(0), data_(size_) {}

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    data_[calcIndex(0)] = value;
    len_++;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    len_--;
    start_ = (start_ + 1) % size_;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return kNotFoundSentinel;
    }
    return data_[start_];
  }

  int Rear() {
    if (isEmpty()) {
      return kNotFoundSentinel;
    }
    return data_[calcIndex(-1)];
  }

  bool isEmpty() { return len_ == 0; }

  bool isFull() { return len_ == size_; }

 private:
  static constexpr int kNotFoundSentinel = -1;
  int size_;
  int len_;
  int start_;
  std::vector<int> data_;

  inline int calcIndex(int offset) const {
    return (start_ + len_ + offset) % size_;
  }
};
