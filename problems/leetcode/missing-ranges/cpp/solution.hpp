#pragma once

#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
        std::vector<std::string> result;
        int expected = lower;
        for (auto num : nums) {
            if (num != expected) {
                result.emplace_back(formatRange(expected, num-1));
            }
            expected = num + 1;
        }
        if (expected <= upper) {
            result.emplace_back(formatRange(expected, upper));
        }
        return result;
    }

private:
    inline std::string formatRange(int lower, int upper) {
        formatter_ << lower;
        if (lower != upper) {
            formatter_ << "->" << upper;
        }
        auto result = formatter_.str();
        std::stringstream tmp;
        formatter_.swap(tmp);
        return result;
    }

    std::stringstream formatter_;
};
