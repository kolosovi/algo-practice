#pragma once

#include <algorithm>
#include <utility>
#include <vector>

void Add(std::vector<int> &freq, int &matches, int id) {
  if (freq[id]++ == 0) {
    matches++;
  }
}

void Remove(std::vector<int> &freq, int &matches, int id) {
  if (--freq[id] == 0) {
    matches--;
  }
}

class Solution {
 public:
  std::vector<int> smallestRange(std::vector<std::vector<int>> &nums) {
    std::vector<std::pair<int, int>> points;
    for (int i = 0; i < nums.size(); i++) {
      for (auto num : nums[i]) {
        points.emplace_back(num, i);
      }
    }
    std::sort(points.begin(), points.end());
    std::vector<int> freq(nums.size(), 0);
    int matches = 0;
    int min = -1;
    Add(freq, matches, points.front().second);
    int start = 0, end = 0, min_start = 0, min_end = 0;
    while (end < points.size()) {
      if (matches == nums.size()) {
        if (min == -1 || points[end].first - points[start].first < min) {
          min = points[end].first - points[start].first;
          min_start = start;
          min_end = end;
        }
        Remove(freq, matches, points[start].second);
        start++;
      } else {
        end++;
        if (end < points.size()) {
          Add(freq, matches, points[end].second);
        }
      }
    }
    return std::vector<int>{points[min_start].first, points[min_end].first};
  }
};
