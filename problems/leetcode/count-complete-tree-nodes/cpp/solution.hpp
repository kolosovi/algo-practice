#pragma once

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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int height = 0;
        int left = 1;
        auto *cur = root;
        for (; cur->left != nullptr; height++) {
            left = 2 * left;
            cur = cur->left;
        }
        int right = left * 2 - 1;
        while (left <= right) {
            int middle = (left + right) / 2, path = middle;
            std::vector<int> steps(height, 0);
            for (int i = height-1; i >= 0; --i) {
                steps[i] = path % 2;
                path = path / 2;
            }
            auto *cur = root;
            for (int i = 0; i < height && cur != nullptr; ++i) {
                if (!steps[i]) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }
            if (cur == nullptr) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return right;
    }
};
