#pragma once

#include <algorithm>
#include <istream>
#include <numeric>
#include <ostream>
#include <utility>
#include <vector>

int Search(const std::vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    auto m = l + (r - l) / 2;
    if (nums[m] < target) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return l;
}

class Segtree {
 public:
  Segtree(int l, int r)
      : l_(l), r_(r), count_(0), left_(nullptr), right_(nullptr) {
    if (r - l <= 1) {
      return;
    }
    auto m = l + (r - l) / 2;
    left_ = new Segtree(l, m);
    right_ = new Segtree(m, r);
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

  int Count(int target_l, int target_r) const {
    if (l_ >= target_l && r_ <= target_r) {
      return count_;
    }
    if (left_ == nullptr) {
      return 0;
    }
    if (target_l >= r_ || l_ >= target_r) {
      return 0;
    }
    return left_->Count(target_l, target_r) + right_->Count(target_l, target_r);
  }

 private:
  int l_, r_, count_;
  Segtree *left_, *right_;
};

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> indexes(n);
  std::iota(indexes.begin(), indexes.end(), 0);
  std::vector<int> lower_bounds(n), upper_bounds(n);
  for (int i = 0; i < n; i++) {
    in >> lower_bounds[i] >> upper_bounds[i];
  }
  std::sort(indexes.begin(), indexes.end(),
            [&lower_bounds, &upper_bounds](const int &i, const int &j) {
              if (lower_bounds[i] == lower_bounds[j]) {
                return upper_bounds[i] > upper_bounds[j];
              }
              return lower_bounds[i] < lower_bounds[j];
            });

  // segtree will be built on unique upper bounds
  std::vector<int> unique_upper_bounds(upper_bounds);
  std::sort(unique_upper_bounds.begin(), unique_upper_bounds.end());
  int last_unique_i = 0;
  for (int i = 1; i < n; i++) {
    if (unique_upper_bounds[i] != unique_upper_bounds[last_unique_i]) {
      unique_upper_bounds[++last_unique_i] = unique_upper_bounds[i];
    }
  }
  unique_upper_bounds.resize(last_unique_i + 1);
  std::unordered_map<int, int> ub_to_i;
  for (int i = 0; i < unique_upper_bounds.size(); i++) {
    ub_to_i[unique_upper_bounds[i]] = i;
  }

  std::vector<int> includes_me_count(n, 0), included_by_me_count(n, 0);
  Segtree ltr(0, unique_upper_bounds.size()),
      rtl(0, unique_upper_bounds.size());
  for (int i = 0; i < indexes.size(); i++) {
    auto idx = indexes[i];
    auto ub_i = ub_to_i[upper_bounds[idx]];
    includes_me_count[idx] = ltr.Count(ub_i, unique_upper_bounds.size());
    ltr.Inc(ub_i, 1);
  }
  for (int i = indexes.size() - 1; i >= 0; i--) {
    auto idx = indexes[i];
    auto ub_i = ub_to_i[upper_bounds[idx]];
    included_by_me_count[idx] = rtl.Count(0, ub_i + 1);
    rtl.Inc(ub_i, 1);
  }

  for (int idx = 0; idx < n; idx++) {
    if (idx > 0) {
      out << ' ';
    }
    out << included_by_me_count[idx];
  }
  out << '\n';
  for (int idx = 0; idx < n; idx++) {
    if (idx > 0) {
      out << ' ';
    }
    out << includes_me_count[idx];
  }
  out << '\n';
}
