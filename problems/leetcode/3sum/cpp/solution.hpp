#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> triplets;
        for (int i = 0; i < -2 + nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1, k = nums.size()-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    if (k == nums.size()-1 || nums[k] != nums[k+1]) {
                        std::vector<int> tmp{nums[i], nums[j], nums[k]};
                        triplets.push_back(std::move(tmp));
                    }
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return triplets;
    }
};
