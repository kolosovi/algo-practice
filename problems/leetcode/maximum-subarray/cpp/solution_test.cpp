#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(TestMaxSubArray, 1) {
  Solution solution;
  std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(solution.maxSubArray(nums), 6);
}
