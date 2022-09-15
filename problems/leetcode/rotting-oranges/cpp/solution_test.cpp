#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(OrangesRottingTest, 1) {
  Solution solution;
  std::vector<std::vector<int>> grid{{0, 1}};
  EXPECT_EQ(solution.orangesRotting(grid), -1);
}

TEST(OrangesRottingTest, 2) {
  Solution solution;
  std::vector<std::vector<int>> grid{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
  EXPECT_EQ(solution.orangesRotting(grid), -1);
}
