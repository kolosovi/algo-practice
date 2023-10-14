#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(MaximumScoreFromPerformingMultiplicationOperations, 1) {
  Solution solution;
  std::vector<int> nums{-5, -3, -3, -2, 7, 1};
  std::vector<int> multipliers{-10, -5, 3, 4, 6};
  EXPECT_EQ(102, solution.maximumScore(nums, multipliers));
}
