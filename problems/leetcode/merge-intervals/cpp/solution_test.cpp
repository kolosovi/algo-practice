#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(Merge, 1) {
  Solution solution;
  std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  std::vector<std::vector<int>> expected{{1, 6}, {8, 10}, {15, 18}};
  EXPECT_EQ(solution.merge(intervals), expected);
}
