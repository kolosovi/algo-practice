#pragma once

#include <cstdint>
#include <limits>

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());
    }

private:
    bool isValidBST(TreeNode *node, int64_t min, int64_t max) {
        if (node == nullptr) {
            return true;
        }
        if (node->val < min) {
            return false;
        }
        if (node->val > max) {
            return false;
        }
        int64_t new_max = node->val, new_min = node->val;
        return isValidBST(node->left, min, new_max-1) && isValidBST(node->right, new_min+1, max);
    }
};
