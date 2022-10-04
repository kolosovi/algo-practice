#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int total = 0, min_total = 0, max = -10001;
    for (auto num : nums) {
      total += num;
      max = std::max(max, total - min_total);
      min_total = std::min(min_total, total);
    }
    return max;
  }
};
