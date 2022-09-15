#include <gtest/gtest.h>

#include "solution.hpp"

class MinimumAreaRectangleTest : public ::testing::Test {
 protected:
  Solution solution_;
};

TEST_F(MinimumAreaRectangleTest, 1) {
  std::vector<std::vector<int>> input{{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
  EXPECT_EQ(solution_.minAreaRect(input), 4);
}

TEST_F(MinimumAreaRectangleTest, 2) {
  std::vector<std::vector<int>> input{{1, 1}, {1, 3}, {3, 1},
                                      {3, 3}, {4, 1}, {4, 3}};
  EXPECT_EQ(solution_.minAreaRect(input), 2);
}

TEST_F(MinimumAreaRectangleTest, 3) {
  std::vector<std::vector<int>> input{{1, 4}, {1, 7}, {1, 8}, {1, 12}, {3, 6},
                                      {3, 9}, {5, 4}, {5, 5}, {5, 7},  {5, 8},
                                      {6, 8}, {7, 7}, {8, 4}, {8, 5}};
  EXPECT_EQ(solution_.minAreaRect(input), 3);
}
