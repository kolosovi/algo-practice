#pragma once

#include <istream>
#include <ostream>

class Segtree {
 public:
  Segtree(int l, int r, int initial)
      : l_(l), r_(r), count_(0), left_(nullptr), right_(nullptr) {
    if (l == r - 1) {
      count_ = initial;
      return;
    }
    int m = l + (r - l) / 2;
    left_ = new Segtree(l, m, initial);
    right_ = new Segtree(m, r, initial);
    count_ = left_->count_ + right_->count_;
  }

  void Inc(int i, int value) {
    if (i < l_ || i >= r_) {
      return;
    }
    count_ += value;
    if (left_ == nullptr) {
      return;
    }
    if (i < left_->r_) {
      left_->Inc(i, value);
    } else {
      right_->Inc(i, value);
    }
  }

  int Select(int target_count) const {
    auto *node = this;
    while (node->left_ != nullptr) {
      auto acc = node->left_->count_;
      if (target_count <= acc) {
        node = node->left_;
      } else {
        target_count -= acc;
        node = node->right_;
      }
    }
    return node->l_;
  }

  int Count() const { return count_; }

 private:
  int l_;
  int r_;
  int count_;
  Segtree *left_;
  Segtree *right_;
};

void Solve(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  Segtree set(1, n + 1, 1);
  int offset = k % n;
  while (set.Count() > 0) {
    auto child = set.Select(offset + 1);
    if (set.Count() < n) {
      out << ' ';
    }
    out << child;
    set.Inc(child, -1);
    if (set.Count() == 0) {
      break;
    }
    offset = (offset + k) % set.Count();
  }
  out << '\n';
}
