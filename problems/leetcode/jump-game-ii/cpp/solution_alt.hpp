#pragma once

#include <algorithm>
#include <vector>
#include <functional>

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    std::vector<int> indexes{static_cast<int>(nums.size() - 1)};
    std::vector<int> lengths{0};
    for (int i = nums.size() - 2; i >= 0; i--) {
      auto it = std::lower_bound(indexes.begin(), indexes.end(), i + nums[i],
                                 std::greater<int>{});
      if (it == indexes.end()) {
        continue;
      }
      auto pos = it - indexes.begin();
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
