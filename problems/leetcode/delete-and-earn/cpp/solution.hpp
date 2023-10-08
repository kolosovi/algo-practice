#pragma once

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <utility>

class Solution {
 public:
  int deleteAndEarn(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::pair<int, int>> freq_;
    int count = 1;
    for (int i = 1; i <= nums.size(); i++) {
      if (i == nums.size() || nums[i] != nums[i - 1]) {
        freq_.emplace_back(nums[i - 1], count);
        count = 0;
      }
      count++;
    }
    freq = freq_;
    mem.clear();
    return solve(freq.size() - 1);
  }

  int solve(int i) {
    if (i < 0) {
      return 0;
    }
    auto it = mem.find(i);
    if (it == mem.end()) {
      auto [num, count] = freq[i];
      int total_when_deleted = num * count;
      if (i != 0 && freq[i - 1].first == num - 1) {
        total_when_deleted += solve(i - 2);
      } else {
        total_when_deleted += solve(i - 1);
      }
      mem[i] = std::max(total_when_deleted, solve(i - 1));
    }
    return mem[i];
  }

 private:
  std::vector<std::pair<int, int>> freq;
  std::unordered_map<int, int> mem;
};
