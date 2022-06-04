#pragma once

#include <utility>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> result;
        std::vector<TreeNode*> queue{root};
        while (queue.size() > 0) {
            result.emplace_back();
            auto &level_values = result.back();
            std::vector<TreeNode*> next_queue;
            for (auto node : queue) {
                level_values.emplace_back(node->val);
                if (node->left != nullptr) {
                    next_queue.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    next_queue.emplace_back(node->right);
                }
            }
            std::swap(queue, next_queue);
        }
        return result;
    }
};
