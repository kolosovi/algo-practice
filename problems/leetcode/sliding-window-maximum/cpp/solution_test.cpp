#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(TestMaxSlidingWindow, 1) {
  Solution solution;
  std::vector<int> nums{1, 3, 1, 2, 0, 5};
  std::vector<int> expected{3, 3, 2, 5};
  EXPECT_EQ(solution.maxSlidingWindow(nums, 3), expected);
}
