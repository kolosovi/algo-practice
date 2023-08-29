#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>> &intervals) {
    std::sort(
        intervals.begin(), intervals.end(),
        [&intervals](const std::vector<int> &lhs, const std::vector<int> &rhs) {
          if (lhs[0] == rhs[0]) {
            return lhs[1] < rhs[1];
          }
          return lhs[0] < rhs[0];
        });
    int back = 0;
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[back][1] >= intervals[i][0]) {
        intervals[back][1] = std::max(intervals[back][1], intervals[i][1]);
      } else {
        intervals[++back] = intervals[i];
      }
    }
    intervals.resize(back + 1);
    return intervals;
  }
};
