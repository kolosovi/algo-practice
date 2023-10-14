#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(TestMaximalSquare, 1) {
  Solution solution;
  std::vector<std::vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                        {'1', '0', '1', '1', '1'},
                                        {'1', '1', '1', '1', '1'},
                                        {'1', '0', '0', '1', '0'}};
  EXPECT_EQ(4, solution.maximalSquare(matrix));
}
