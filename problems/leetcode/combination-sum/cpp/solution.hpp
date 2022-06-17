#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return rec(candidates, target, 0);
    }

private:
    std::vector<std::vector<int>> rec(std::vector<int>& candidates, int target, int start) {
        if (start == candidates.size()) {
            return {};
        }
        if (candidates[start] > target) {
            return {};
        }
        std::vector<std::vector<int>> result;
        int count = target / candidates[start], max_sum = target - (target % candidates[start]);
        std::vector<int> tail(count, candidates[start]);
        for (int sum = max_sum; sum >= 0; sum -= candidates[start]) {
            if (sum == target) {
                result.push_back(tail);
            } else {
                for (auto combination : rec(candidates, target - sum, start + 1)) {
                    combination.insert(combination.end(), tail.begin(), tail.end());
                    result.push_back(std::move(combination));
                }
            }
            tail.pop_back();
        }
        return result;
    }
};
