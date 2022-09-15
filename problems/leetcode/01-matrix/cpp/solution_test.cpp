#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(Problem01MatrixTest, 1) {
  Solution solution;
  std::vector<std::vector<int>> input{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  std::vector<std::vector<int>> expected{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  EXPECT_EQ(solution.updateMatrix(input), expected);
}
