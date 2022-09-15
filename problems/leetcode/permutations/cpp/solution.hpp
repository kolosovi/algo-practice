#pragma once

#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    while (true) {
      result.push_back(nums);
      int pivot = -1;
      for (int i = nums.size() - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
          pivot = i - 1;
          break;
        }
      }
      if (pivot < 0) {
        break;
      }
      int min_i = -1;
      for (int i = pivot + 1; i < nums.size(); i++) {
        if (nums[i] < nums[pivot]) {
          continue;
        }
        if (min_i == -1 || nums[i] < nums[min_i]) {
          min_i = i;
        }
      }
      std::swap(nums[pivot], nums[min_i]);
      for (int l = pivot + 1, r = nums.size() - 1; l < r; l++, r--) {
        std::swap(nums[l], nums[r]);
      }
    }
    return result;
  }
};
