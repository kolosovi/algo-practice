#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(RightSideViewTest, 1) {
  Solution solution;
  auto *root = new TreeNode(42);
  std::vector<int> expected{42};
  EXPECT_EQ(solution.rightSideView(root), expected);
}
