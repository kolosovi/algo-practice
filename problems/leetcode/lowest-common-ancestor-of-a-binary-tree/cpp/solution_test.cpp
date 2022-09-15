#include <gtest/gtest.h>

#include "solution.hpp"

TEST(LowestCommonAncestorTest, 1) {
  Solution solution;
  TreeNode *root = new TreeNode(
      3,
      new TreeNode(5, new TreeNode(6),
                   new TreeNode(2, new TreeNode(7), new TreeNode(4))),
      new TreeNode(1, new TreeNode(0), new TreeNode(8)));
  TreeNode *p = root->left, *q = root->right, *expected = root;
  EXPECT_EQ(solution.lowestCommonAncestor(root, p, q), expected);
}

TEST(LowestCommonAncestorTest, 2) {
  Solution solution;
  TreeNode *root = new TreeNode(
      3,
      new TreeNode(5, new TreeNode(6),
                   new TreeNode(2, new TreeNode(7), new TreeNode(4))),
      new TreeNode(1, new TreeNode(0), new TreeNode(8)));
  TreeNode *p = root->left, *q = root->left->right->right,
           *expected = root->left;
  EXPECT_EQ(solution.lowestCommonAncestor(root, p, q), expected);
}

TEST(LowestCommonAncestorTest, 3) {
  Solution solution;
  TreeNode *root = new TreeNode(1, new TreeNode(5), nullptr);
  TreeNode *p = root, *q = root->left, *expected = root;
  EXPECT_EQ(solution.lowestCommonAncestor(root, p, q), expected);
}
