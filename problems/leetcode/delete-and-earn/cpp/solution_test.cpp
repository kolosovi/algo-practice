#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(DeleteAndEarn, 1) {
  Solution solution;
  std::vector<int> nums{2, 2, 3, 3, 3, 4};
  EXPECT_EQ(9, solution.deleteAndEarn(nums));
}
