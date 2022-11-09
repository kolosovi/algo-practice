// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <vector>
#include <numeric>

class RingBuf {
 public:
  RingBuf(const std::vector<int> &data)
      : data_(data), kLimit_(data.size()), len_(data.size()), start_(0) {}

  int PopFront() {
    auto front = data_[start_];
    len_--;
    if (++start_ == data_.size()) {
      start_ = 0;
    }
    return front;
  }

  void PushBack(int value) { data_[(start_ + len_++) % data_.size()] = value; }

  bool IsEmpty() const { return len_ == 0; }

 private:
  std::vector<int> data_;
  int kLimit_;
  int len_;
  int start_;
};

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> children(n);
  std::iota(children.begin(), children.end(), 1);
  RingBuf buf(children);
  buf.PushBack(buf.PopFront());
  while (!buf.IsEmpty()) {
    out << buf.PopFront();
    if (buf.IsEmpty()) {
      out << '\n';
      return;
    }
    out << ' ';
    buf.PushBack(buf.PopFront());
  }
}

int main() { Solve(std::cin, std::cout); }
