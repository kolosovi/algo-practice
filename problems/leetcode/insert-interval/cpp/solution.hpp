#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        auto insert_before_it = std::lower_bound(intervals.begin(), intervals.end(), newInterval, [](const std::vector<int> &lhs, const std::vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        auto pos = intervals.insert(insert_before_it, newInterval);
        auto index = pos - intervals.begin();
        if (index > 0) {
            index--;
        }
        int count = index + 1;
        for (int i = index + 1; i < intervals.size(); i++) {
            if (intervals[index][1] >= intervals[i][0]) {
                intervals[index][1] = std::max(intervals[index][1], intervals[i][1]);
            } else {
                index++;
                intervals[count++] = intervals[i];
            }
        }
        intervals.resize(count);
        return intervals;
    }
};
