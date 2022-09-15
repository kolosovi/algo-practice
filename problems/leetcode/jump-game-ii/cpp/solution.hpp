#pragma once

#include <vector>

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    std::vector<int> indexes{static_cast<int>(nums.size() - 1)};
    std::vector<int> lengths{0};
    for (int i = nums.size() - 2; i >= 0; i--) {
      int pos = indexes.size() - 1;
      for (; pos >= 0; pos--) {
        if (indexes[pos] > i + nums[i]) {
          break;
        }
      }
      if (pos == indexes.size() - 1) {
        continue;
      }
      pos++;
      while (indexes.size() > pos + 1) {
        indexes.pop_back();
        lengths.pop_back();
      }
      indexes.push_back(i);
      lengths.push_back(lengths[pos] + 1);
    }
    return lengths.back();
  }
};
