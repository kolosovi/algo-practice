#pragma once

#include <vector>
#include <algorithm>

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
  std::vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    std::vector<TreeNode *> queue{root};
    std::vector<int> result;
    while (queue.size() > 0) {
      std::vector<TreeNode *> next_queue;
      for (int i = 0; i < queue.size(); i++) {
        if (queue[i]->left != nullptr) {
          next_queue.push_back(queue[i]->left);
        }
        if (queue[i]->right != nullptr) {
          next_queue.push_back(queue[i]->right);
        }
        if (i == queue.size() - 1) {
          result.push_back(queue[i]->val);
        }
      }
      std::swap(queue, next_queue);
    }
    return result;
  }
};
