#pragma once

#include <algorithm>
#include <vector>

/*
1. the answer is max by i (length of LIS ending at number i)
2. LIS(i) = max by j < i & nums_j < nums_i LIS(j) + 1 OR 1

so the answer can be calculated recursively (base is LIS(0) = 1)

this will have exponential runtime since esseantially we're splitting the
preceding interval into k parts at each step.

memoization (of LIS(i)) brings it down to O(n^2), still not good enough.

let j1, j2: j1 < i & j2 < i & nums_j1 < nums_i & nums_j2 < nums_i.

without loss of generality, j1 < j2.

Cases:
nums_j1 = nums_j2. Then we should pick j2 for calculating LIS(i) because j2's
    LIS will include all the numbers in j1's LIS and probably more.
nums_j1 < nums_j2. Same
nums_j1 > nums_j2

Oh. If nums_j1 < nums_j2 AND LIS(j1) <= LIS(j2), I just throw away j1.

0
|
v
n-1

Algorithm:
initialize empty prev array
for num in nums:
    find greatest number <= num in prev (might be None if num is the minimum
one) if there is a number after found: subsitutite it with num otherwise, add
num to end of array

Obs. 1: at each point, numbers in array have strictly monotonically increasing
values AND their lengths grow by 1. Proof:
    - observation holds for empty array
    - array of 1 (with only the first number of nums): observation also holds
    - array of 2: observation holds because if we add a number to array of 1 its
LIS will be equal to preceding LIS + 1. If we replace the old number, it also
holds.
    - say it holds for an array of n & a new number is added.
        - if a number is replaced with the new one, the observation holds
        - if its added to the end, it also holds

Obs. 2: any number that's replaced is not needed for further calculations
    - it's true because it has the same LIS as the new one but it's larger, so
the LIS that STARTS with the new number is larger than or equal to the LIS that
STARTS with the replaced number
*/

class Solution {
 public:
  int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> stack;
    for (auto num : nums) {
      auto lb = std::lower_bound(stack.begin(), stack.end(), num);
      if (lb == stack.end()) {
        stack.push_back(num);
      } else {
        *lb = num;
      }
    }
    return static_cast<int>(stack.size());
  }
};
