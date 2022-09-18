#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  int trap(std::vector<int>& height) {
    std::vector<int> stack;
    int total = 0;
    for (int i = 0; i < height.size(); i++) {
      int last_height = 0;
      while (stack.size() > 0) {
        auto top_i = stack.back();
        total += (i - top_i - 1) *
                 (std::min(height[i], height[top_i]) - last_height);
        last_height = height[top_i];
        if (height[top_i] > height[i]) {
          break;
        }
        stack.pop_back();
      }
      stack.push_back(i);
    }
    return total;
  }
};
