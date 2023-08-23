#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(SearchRange, 1) {
  Solution solution;
  std::vector<int> nums{5, 7, 7, 8, 8, 10};
  std::vector<int> expected{3, 4};
  EXPECT_EQ(solution.searchRange(nums, 8), expected);
}
