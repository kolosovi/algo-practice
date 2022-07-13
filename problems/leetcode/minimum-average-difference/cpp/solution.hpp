#pragma once

#include <cstdint>
#include <vector>

class Solution {
public:
    int minimumAverageDifference(std::vector<int>& nums) {
        int64_t total = 0;
        for (auto num : nums) {
            total += num;
        }
        int64_t left_sum = 0, min_diff = -1;
        int min_i = -1;
        for (int i = 0; i < nums.size(); i++) {
            left_sum += static_cast<int64_t>(nums[i]);
            auto diff = left_sum / static_cast<int64_t>(i+1);
            if (i != nums.size() - 1) {
                diff -= (total - left_sum) / static_cast<int64_t>(nums.size()-i-1);
            }
            if (diff < 0) {
                diff = -diff;
            }
            if (min_diff == -1 || diff < min_diff) {
                min_diff = diff;
                min_i = i;
            }
        }
        return min_i;
    }
};
