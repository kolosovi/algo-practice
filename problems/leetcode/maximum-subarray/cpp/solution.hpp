#pragma once

#include <algorithm>
#include <limits>
#include <vector>

/*
basic idea: I want to find maximum sum R_i: it's the maximum sum that a subarray
ending at index i can have. & intuitively it's just S_i - min(S_j) over j < i.

DP approach?
1. state variable(s)? There MUST be only one. Say dp(i) is the largest subarray
sum for an array ending at i, so the answer is max(dp(i)) for all i's.
2. base cases? dp(0) is just 0. dp(1) is just... what?
3. transition?

I'm loking at the ith number. I have dp(i-1): the largest subarray sum for
arrays ending with i-1-th number. Basically I have two options:
- continue the largest subarray
- start anew

And it's easy, I just pick the largest option: dp(i) = std::max(dp(i-1) +
nums_i, nums_i). I also update the result on encountering each i. dp(i-1) can be
set to 0 initially.
*/
class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int max = std::numeric_limits<int>::min(), cur = 0;
    for (auto num : nums) {
      cur = std::max(cur + num, num);
      max = std::max(max, cur);
    }
    return max;
  }
};

class SolutionOld {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int total = 0, min_total = 0, max = -10001;
    for (auto num : nums) {
      total += num;
      max = std::max(max, total - min_total);
      min_total = std::min(min_total, total);
    }
    return max;
  }
};
