#pragma once

#include <string>
#include <algorithm>
#include <vector>

class Solution {
 public:
  int longestValidParentheses(std::string s) {
    std::vector<std::pair<int, int>> track(s.size(), {-1, -1});
    std::vector<int> stack;
    int max = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stack.emplace_back(i);
        continue;
      }
      if (stack.empty()) {
        continue;
      }
      auto start = stack.back();
      stack.pop_back();
      max = std::max(max, i - start + 1);
      auto [prev_start, prev_end] = track[stack.size()];
      if (prev_start == -1 || prev_end < start - 1) {
        track[stack.size()] = {start, i};
        continue;
      }
      track[stack.size()] = {prev_start, i};
      max = std::max(max, i - prev_start + 1);
    }
    return max;
  }
};
