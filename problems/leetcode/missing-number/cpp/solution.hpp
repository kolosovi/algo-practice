#pragma once

#include <vector>

class Solution {
 public:
  int missingNumber(std::vector<int>& nums) {
    int expected_total = (nums.size() * (nums.size() + 1)) / 2;
    int total = 0;
    for (auto num : nums) {
      total += num;
    }
    return expected_total - total;
  }
};
