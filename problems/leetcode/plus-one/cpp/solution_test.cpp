#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(PlusOneTest, 1) {
  Solution solution;
  std::vector<int> digits{0};
  std::vector<int> expected{1};
  EXPECT_EQ(solution.plusOne(digits), expected);
}

TEST(PlusOneTest, 2) {
  Solution solution;
  std::vector<int> digits{9};
  std::vector<int> expected{1, 0};
  EXPECT_EQ(solution.plusOne(digits), expected);
}

TEST(PlusOneTest, 3) {
  Solution solution;
  std::vector<int> digits{9, 9};
  std::vector<int> expected{1, 0, 0};
  EXPECT_EQ(solution.plusOne(digits), expected);
}

TEST(PlusOneTest, 4) {
  Solution solution;
  std::vector<int> digits{9, 8};
  std::vector<int> expected{9, 9};
  EXPECT_EQ(solution.plusOne(digits), expected);
}
