#pragma once

#include <vector>
#include <algorithm>

/*
dp(i, j): how much CAN we earn if we ALREADY made i left ops & j right ops.
^ this might be a pattern.

so dp(0, 0) is the asnswer.
dp(i, j): it means that we are doing operation i+j (0 indexed).
we can take it from the left or from the right.
from the left: nums[i] * multipliers[i+j], and we must solve dp(i+1, j)
from the right: nums[nums.size() -j - 1] * multipliers[i+j], and we must solve
dp(i, j+1)

base case: operation i+j is >= multipliers.size(), so 0.

base case: no ops left!! so dp actually should represent the work that's not
done yet, work to be done
*/
class Solution {
 public:
  int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {
    std::vector<int> mem(multipliers.size(), -1);
    for (int total_ops = multipliers.size() - 1; total_ops >= 0; total_ops--) {
      for (int i = 0; i <= total_ops; ++i) {
        int j = total_ops - i;
        int left = (total_ops == multipliers.size() - 1) ? 0 : mem[i + 1];
        int right = (total_ops == multipliers.size() - 1) ? 0 : mem[i];
        mem[i] =
            std::max(left + multipliers[i + j] * nums[i],
                     right + multipliers[i + j] * nums[nums.size() - j - 1]);
      }
    }
    return mem[0];
  }
};

// less dense tabulation solution

class Solution1 {
 public:
  int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {
    std::vector<int> memrow(multipliers.size(), -1);
    std::vector<std::vector<int>> mem(multipliers.size(), memrow);
    for (int total_ops = multipliers.size() - 1; total_ops >= 0; total_ops--) {
      for (int i = 0; i <= total_ops; ++i) {
        int j = total_ops - i;
        int left = (i + j + 1 == multipliers.size()) ? 0 : mem[j][i + 1];
        int right = (i + j + 1 == multipliers.size()) ? 0 : mem[j + 1][i];
        mem[j][i] =
            std::max(left + multipliers[i + j] * nums[i],
                     right + multipliers[i + j] * nums[nums.size() - j - 1]);
      }
    }
    return mem[0][0];
  }
};

// memoization solution (the most accessible one)

class Solution2 {
 public:
  int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {
    this->nums = nums;
    this->multipliers = multipliers;
    mem.resize(this->multipliers.size());
    for (auto& memrow : mem) {
      memrow.resize(this->multipliers.size());
      for (auto& num : memrow) {
        num = -1;
      }
    }
    return dp(0, 0);
  }

 private:
  std::vector<int> nums;
  std::vector<int> multipliers;
  std::vector<std::vector<int>> mem;

  int dp(int i, int j) {
    if (i + j >= multipliers.size()) {
      return 0;
    }
    if (mem[i][j] == -1) {
      mem[i][j] = std::max(
          dp(i + 1, j) + multipliers[i + j] * nums[i],
          dp(i, j + 1) + multipliers[i + j] * nums[nums.size() - j - 1]);
    }
    return mem[i][j];
  }
};
