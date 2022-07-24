#pragma once

#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int total = 0;
        for (auto num : nums) {
            total += num;
        }
        int target = total / 2, rem = total % 2;
        if (rem != 0) {
            return false;
        }
        std::vector<int> mem_row(20001, -1);
        std::vector<std::vector<int>> mem(nums.size(), mem_row);
        for (int start = 0; start < nums.size(); start++) {
            if (hasTarget(nums, mem, start, target)) {
                return true;
            }
        }
        return false;
    }

private:
    bool hasTarget(const std::vector<int> &nums, std::vector<std::vector<int>> & mem, int start, int target) {
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        if (start >= nums.size()) {
            return false;
        }
        if (mem[start][target] != -1) {
            return mem[start][target] == 1;
        }
        if (hasTarget(nums, mem, start+1, target-nums[start])) {
            mem[start][target] = 1;
            return true;
        }
        mem[start][target] = hasTarget(nums, mem, start+1, target);
        return mem[start][target];
    }
};
