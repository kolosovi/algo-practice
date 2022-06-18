#include <gtest/gtest.h>

#include "solution.hpp"

TEST(IsValidBSTTest, 1) {
    Solution solution;
    TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2));
    EXPECT_TRUE(solution.isValidBST(root));
}

TEST(IsValidBSTTest, 2) {
    Solution solution;
    TreeNode *root = new TreeNode(2, nullptr, new TreeNode(1));
    EXPECT_FALSE(solution.isValidBST(root));
}

TEST(IsValidBSTTest, 3) {
    Solution solution;
    TreeNode *root = new TreeNode(
            12,
            new TreeNode(
                11,
                new TreeNode(
                    7,
                    nullptr,
                    new TreeNode(
                        9,
                        new TreeNode(8),
                        new TreeNode(10)
                    )
                ),
                nullptr
            ),
            nullptr
    );
    EXPECT_TRUE(solution.isValidBST(root));
}

TEST(IsValidBSTTest, 4) {
    Solution solution;
    TreeNode *root = new TreeNode(
            12,
            new TreeNode(
                11,
                new TreeNode(
                    7,
                    nullptr,
                    new TreeNode(
                        9,
                        new TreeNode(10),
                        new TreeNode(9)
                    )
                ),
                nullptr
            ),
            nullptr
    );
    EXPECT_FALSE(solution.isValidBST(root));
}
