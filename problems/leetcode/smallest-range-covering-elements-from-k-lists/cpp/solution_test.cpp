#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(TestSmallestRange, 1) {
  Solution solution;
  std::vector<std::vector<int>> nums{
      {4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
  std::vector<int> expected{20, 24};
  EXPECT_EQ(solution.smallestRange(nums), expected);
}
