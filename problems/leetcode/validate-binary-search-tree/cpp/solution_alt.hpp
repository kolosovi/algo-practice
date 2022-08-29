#pragma once

#include <cstdint>
#include <limits>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

enum EntryPoint {
    INIT,
    AFTER_LEFT,
    AFTER_RIGHT
};

class Solution {
public:
    Solution() : prev(nullptr) {}

    bool isValidBST(TreeNode* root) {
        std::vector<std::tuple<TreeNode*, int>> stack;
        stack.emplace_back(root, INIT);
        TreeNode *prev = nullptr;
        bool ret = false;
        while (stack.size() > 0) {
            auto [node, entry_point] = stack.back();
            stack.pop_back();
            if (node == nullptr) {
                ret = true;
                continue;
            }
            switch (entry_point) {
                case INIT:
                    stack.emplace_back(node, AFTER_LEFT);
                    stack.emplace_back(node->left, INIT);
                    break;
                case AFTER_LEFT:
                    if (ret == false) {
                        continue;
                    }
                    if (prev != nullptr && node->val <= prev->val) {
                        ret = false;
                        continue;
                    }
                    prev = node;
                    stack.emplace_back(node, AFTER_RIGHT);
                    stack.emplace_back(node->right, INIT);
                    break;
                case AFTER_RIGHT:
                    break;
            }
        }
        return ret;
    }

private:
    TreeNode* prev;
};
