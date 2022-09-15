#pragma once

#include <cstdint>
#include <limits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    TreeNode *prev = nullptr, *node = root;
    std::vector<TreeNode *> stack;
    while (true) {
      if (node->left != nullptr) {
        stack.emplace_back(node);
        node = node->left;
        continue;
      }
      if (prev != nullptr && prev->val >= node->val) {
        return false;
      }
      prev = node;
      if (node->right != nullptr) {
        node = node->right;
        continue;
      }
      if (stack.size() == 0) {
        return true;
      }
      node = stack.back();
      node->left = nullptr;
      stack.pop_back();
    }
    return true;
  }
};
