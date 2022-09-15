#pragma once

#include <string>
#include <vector>
#include <sstream>

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
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> result;
    std::vector<TreeNode *> path;
    TreeNode *current = root, *prev = nullptr;
    while (current != nullptr) {
      TreeNode *up = nullptr;
      if (path.size() > 0) {
        up = path.back();
      }
      if (!current->left && !current->right) {
        std::stringstream path_desc;
        for (auto *node : path) {
          path_desc << node->val << "->";
        }
        path_desc << current->val;
        result.push_back(path_desc.str());
      }
      // there are three options:
      // 1. go left: if we came from up and left is present
      // 2. go right: if we can't go left AND (right is present and (we came
      // from up OR we came from left))
      // 3. go up: all other options
      if (prev == up && current->left) {
        path.push_back(current);
        prev = current;
        current = current->left;
      } else if (current->right && (prev == up || prev == current->left)) {
        path.push_back(current);
        prev = current;
        current = current->right;
      } else {
        if (path.size() > 0) {
          path.pop_back();
        }
        prev = current;
        current = up;
      }
    }
    return result;
  }
};
