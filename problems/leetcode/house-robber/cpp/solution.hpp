#pragma once

#include <algorithm>
#include <vector>

/*
n is the number of houses.
     i
[2,7,9,3,1]

M_i is the solution for houses up to i_th EXclusive (i.e. it doesn't rob the ith
house). In this case the solution is equal to M_n.

We know M_0 (it's 0). We know M_1 (it's 0).

Say we already know M_(i-1).

M_i = max{M_(i-1), M_(i-2) + houses_(i-1))



M_(i+1)?

M_i = max{M_(i-2) + houses_i, M_(i-3) + houses_(i-1)}
*/
class Solution {
 public:
  int rob(std::vector<int>& nums) {
    int prevprev = 0, prev = nums[0], cur = nums[0];
    for (int i = 2; i <= nums.size(); i++) {
      cur = std::max(prev, prevprev + nums[i - 1]);
      prevprev = prev;
      prev = cur;
    }
    return cur;
  }
};
