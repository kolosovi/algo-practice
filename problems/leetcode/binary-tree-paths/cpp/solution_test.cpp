#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "solution.hpp"

TEST(BinaryTreePathsTest, 1) {
    Solution solution;
    TreeNode *root = new TreeNode(
        1,
        new TreeNode(
            2,
            nullptr,
            new TreeNode(5)
        ),
        new TreeNode(3)
    );
    std::vector<std::string> expected{"1->2->5", "1->3"};
    EXPECT_EQ(solution.binaryTreePaths(root), expected);
}
