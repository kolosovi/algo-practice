#pragma once

#include <vector>
#include <deque>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::deque<int> window;
    std::vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      while (window.size() > 0 && i - window.front() >= k) {
        window.pop_front();
      }
      while (window.size() > 0 && nums[window.back()] <= nums[i]) {
        window.pop_back();
      }
      window.push_back(i);
      if (i >= k - 1) {
        result.push_back(nums[window.front()]);
      }
    }
    return result;
  }
};
