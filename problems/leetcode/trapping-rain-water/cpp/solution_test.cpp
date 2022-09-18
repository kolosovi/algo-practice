#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(TestTrap, 1) {
  Solution solution;
  std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  EXPECT_EQ(solution.trap(height), 6);
}

TEST(TestTrap, 2) {
  Solution solution;
  std::vector<int> height{4, 2, 0, 3, 2, 5};
  EXPECT_EQ(solution.trap(height), 9);
}
