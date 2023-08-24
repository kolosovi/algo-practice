#pragma once

#include <algorithm>
#include <vector>

struct Segtree {
  int lb;
  int rb;
  int count = 0;
  Segtree *left = nullptr;
  Segtree *right = nullptr;

  Segtree(int lb, int rb) : lb(lb), rb(rb) {
    if (rb - lb <= 1) {
      return;
    }
    auto right_start = lb + (rb - lb) / 2;
    left = new Segtree(lb, right_start);
    right = new Segtree(right_start, rb);
  }

  void incr(int pos) {
    count += 1;
    if (left != nullptr && pos < left->rb) {
      left->incr(pos);
    } else if (right != nullptr) {
      right->incr(pos);
    }
  }

  int count_less_than(int pos) {
    if (left == nullptr) {
      return 0;
    }
    if (pos < left->rb) {
      return left->count_less_than(pos);
    }
    return left->count + right->count_less_than(pos);
  }
};

int find_lower_bound(const std::vector<int> &nums, int target) {
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

class Solution {
 public:
  std::vector<int> countSmaller(std::vector<int> &nums) {
    std::vector<int> uniques(nums);
    std::sort(uniques.begin(), uniques.end());
    int i = 0;
    for (int j = 1; j < uniques.size(); ++j) {
      if (uniques[j] != uniques[i]) {
        i++;
        uniques[i] = uniques[j];
      }
    }
    uniques.resize(i + 1);
    Segtree tree(0, uniques.size());
    std::vector<int> result(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; i--) {
      auto lower_bound = find_lower_bound(uniques, nums[i]);
      result[i] = tree.count_less_than(lower_bound);
      tree.incr(lower_bound);
    }
    return result;
  }
};
