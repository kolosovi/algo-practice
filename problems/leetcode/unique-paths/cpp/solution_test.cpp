#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(UniquePathsTest, 1) {
  Solution solution;
  EXPECT_EQ(solution.uniquePaths(1, 1), 1);
}

TEST(UniquePathsTest, 2) {
  Solution solution;
  EXPECT_EQ(solution.uniquePaths(3, 7), 28);
}

TEST(UniquePathsTest, 3) {
  Solution solution;
  EXPECT_EQ(solution.uniquePaths(3, 2), 3);
}

TEST(UniquePathsTest, 4) {
  Solution solution;
  EXPECT_EQ(solution.uniquePaths(6, 3), 21);
}
