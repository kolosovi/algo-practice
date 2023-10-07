#include <gtest/gtest.h>

#include "solution.hpp"

TEST(LongestIncreasingSubsequence, 1) {
  Solution solution;
  std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  EXPECT_EQ(4, solution.lengthOfLIS(nums));
}
