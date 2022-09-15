#pragma once

#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int findMinDifference(std::vector<std::string>& timePoints) {
    std::vector<int> minutes;
    minutes.reserve(timePoints.size());
    for (const auto& point : timePoints) {
      minutes.emplace_back(60 * (10 * (point[0] - '0') + point[1] - '0') +
                           10 * (point[3] - '0') + point[4] - '0');
    }
    std::sort(minutes.begin(), minutes.end());
    const int minutes_in_day = 1440;
    int min = minutes_in_day;
    for (int i = 1; i < minutes.size(); i++) {
      min = std::min(min, minutes[i] - minutes[i - 1]);
    }
    return std::min(min, minutes_in_day + minutes.front() - minutes.back());
  }
};
