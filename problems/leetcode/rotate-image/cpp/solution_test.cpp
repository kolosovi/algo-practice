#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(RotateTest, 1) {
  Solution solution;
  std::vector<std::vector<int>> matrix{
      {5, 1, 9, 11},
      {2, 4, 8, 10},
      {13, 3, 6, 7},
      {15, 14, 12, 16},
  };
  solution.rotate(matrix);
  std::vector<std::vector<int>> expected{
      {15, 13, 2, 5},
      {14, 3, 4, 1},
      {12, 6, 8, 9},
      {16, 7, 10, 11},
  };
  EXPECT_EQ(expected, matrix);
}
