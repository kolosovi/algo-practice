#include <gtest/gtest.h>

#include "solution.hpp"

TEST(HouseRobber, 1) {
  Solution solution;
  std::vector<int> nums{2, 7, 9, 3, 1};
  EXPECT_EQ(12, solution.rob(nums));
}
