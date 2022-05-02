#pragma once

#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k < 1) {
            return 0;
        }
        int product = 1, l = 0, r = 0, prev_r = 0, result = 0;
        while (true) {
            for (; r < nums.size(); r++) {
                product *= nums[r];
                if (product >= k) {
                    break;
                }
            }
            result += numSubarrays(l, r);
            if (prev_r > l) {
                result -= numSubarrays(l, prev_r);
            }
            prev_r = r;
            if (r == nums.size()) {
                return result;
            }
            for (; product >= k && l <= r; l++) {
                product /= nums[l];
            }
            r++;
        }
        return result;
    }

    inline int numSubarrays(int first, int after_last) {
        return ((after_last - first) * (after_last - first + 1)) / 2;
    }
};
