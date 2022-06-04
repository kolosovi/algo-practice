#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(LevelOrderTest, 1) {
    Solution solution;
    auto tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    std::vector<std::vector<int>> expected{{3}, {9, 20}, {15, 7}};
    EXPECT_EQ(solution.levelOrder(tree), expected);
}
