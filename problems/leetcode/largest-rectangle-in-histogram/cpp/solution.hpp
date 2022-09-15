#pragma once

#include <algorithm>
#include <vector>
#include <utility>

class Solution {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    int max = 0;
    std::vector<std::pair<int, int>> rects;
    for (auto h_rit = heights.rbegin(); h_rit != heights.rend(); h_rit++) {
      auto h = *h_rit;
      if (rects.size() == 0) {
        max = std::max(max, h);
        rects.emplace_back(h, 1);
        continue;
      }
      int total_w = 0;
      while (rects.size() > 0 && rects.back().first >= h) {
        auto [rect_h, rect_w] = rects.back();
        max = std::max(max, rect_h * rect_w);
        total_w += rect_w;
        max = std::max(max, rect_h * total_w);
        rects.pop_back();
      }
      rects.emplace_back(h, total_w + 1);
    }
    int total_w = 0;
    for (auto rect_rit = rects.rbegin(); rect_rit != rects.rend(); rect_rit++) {
      auto [rect_h, rect_w] = *rect_rit;
      max = std::max(max, rect_h * rect_w);
      total_w += rect_w;
      max = std::max(max, rect_h * total_w);
    }
    return max;
  }
};
