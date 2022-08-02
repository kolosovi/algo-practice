#pragma once

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        return subsets(0, nums);
    }

private:
    std::vector<std::vector<int>> subsets(int start, std::vector<int>& nums) {
        if (start == nums.size()) {
            return {{}};
        }
        auto result = subsets(start+1, nums);
        int size = result.size();
        result.reserve(size * 2);
        for (int i = 0; i < size; i++) {
            result.push_back(result[i]);
            result.back().push_back(nums[start]);
        }
        return result;
    }
};
