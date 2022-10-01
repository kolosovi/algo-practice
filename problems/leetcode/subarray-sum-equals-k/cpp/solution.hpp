#pragma once

#include <vector>
#include <unordered_map>

class Solution {
 public:
  int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> counts{{0, 1}};
    int result = 0, total = 0;
    for (auto num : nums) {
      total += num;
      result += counts[total - k];
      counts[total]++;
    }
    return result;
  }
};
