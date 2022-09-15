#include <gtest/gtest.h>

#include "solution.hpp"

TEST(TestLargestRectangleArea, 1) {
  Solution solution;
  std::vector<int> heights{2, 1, 5, 6, 2, 3};
  EXPECT_EQ(solution.largestRectangleArea(heights), 10);
}

TEST(TestLargestRectangleArea, 2) {
  Solution solution;
  std::vector<int> heights{2, 4};
  EXPECT_EQ(solution.largestRectangleArea(heights), 4);
}
