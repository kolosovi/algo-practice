#pragma once

#include <algorithm>

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
    int maxPathSum(TreeNode* root) {
        int result = -1001;
        maxHalfPathSum(root, result);
        return result;
    }

    int maxHalfPathSum(TreeNode *node, int &maxPathSum) {
        int maxLeftHalfPathSum = 0, maxRightHalfPathSum = 0;
        if (node->left != nullptr) {
            maxLeftHalfPathSum = maxHalfPathSum(node->left, maxPathSum);
        }
        if (node->right != nullptr) {
            maxRightHalfPathSum = maxHalfPathSum(node->right, maxPathSum);
        }
        auto result = std::max({node->val, node->val + maxLeftHalfPathSum, node->val + maxRightHalfPathSum});
        maxPathSum = std::max({maxPathSum, result, node->val + maxLeftHalfPathSum + maxRightHalfPathSum});
        return result;
    }
};
