#include <gtest/gtest.h>

#include <vector>

#include "solution.hpp"

TEST(MaximumProductSubarray, 1) {
  Solution solution;
  std::vector<int> nums{2, 3, -2, 4};
  EXPECT_EQ(6, solution.maxProduct(nums));
}

TEST(MaximumProductSubarray, 2) {
  Solution solution;
  std::vector<int> nums{-2, 0, -1};
  EXPECT_EQ(0, solution.maxProduct(nums));
}
