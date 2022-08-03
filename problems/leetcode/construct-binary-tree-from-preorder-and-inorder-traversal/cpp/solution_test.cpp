#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(BuildTree, 1) {
    Solution solution;
    std::vector<int> preorder{-1};
    std::vector<int> inorder{-1};
    auto *actual = solution.buildTree(preorder, inorder);
    EXPECT_NE(actual, nullptr);
    EXPECT_EQ(actual->left, nullptr);
    EXPECT_EQ(actual->right, nullptr);
    EXPECT_EQ(actual->val, -1);
}
