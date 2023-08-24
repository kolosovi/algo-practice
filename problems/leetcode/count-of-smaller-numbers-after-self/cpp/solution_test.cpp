#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(CountSmaller, 1) {
  Solution solution;
  std::vector<int> nums{5, 2, 6, 1};
  std::vector<int> expected{2, 1, 1, 0};
  EXPECT_EQ(solution.countSmaller(nums), expected);
}
