#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumTop(std::vector<int>& nums, int k) {
    if (nums.size() == 1) {
      return k % 2 == 1 ? -1 : nums[0];
    }
    int result = -1;
    for (int i = 0; i <= k && i < nums.size(); i++) {
      if (i != k - 1) {
        result = std::max(result, nums[i]);
      }
    }
    return result;
  }
};
