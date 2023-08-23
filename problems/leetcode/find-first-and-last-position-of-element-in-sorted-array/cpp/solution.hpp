#pragma once

#include <vector>

struct LowerBound {
  bool operator()(const int &num) const { return num < target; }
  int target;
};

struct UpperBound {
  bool operator()(const int &num) const { return num <= target; }
  int target;
};

template <typename Comparator>
int search(const std::vector<int> &nums, Comparator comp) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (comp(nums[m])) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return l;
}

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    LowerBound lower_bound{target};
    UpperBound upper_bound{target};
    auto first_i = search(nums, lower_bound);
    if (first_i == nums.size() || nums[first_i] != target) {
      return {-1, -1};
    }
    auto after_last_i = search(nums, upper_bound);
    return {first_i, after_last_i - 1};
  }
};
