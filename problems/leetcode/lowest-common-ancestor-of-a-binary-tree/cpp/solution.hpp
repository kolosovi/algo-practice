#pragma once

#include <algorithm>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> p_path, q_path, path;
        TreeNode *cur = root, *prev = nullptr;
        while (p_path.size() == 0 || q_path.size() == 0) {
            if (cur == p) {
                p_path.insert(p_path.end(), path.begin(), path.end());
                p_path.push_back(cur);
            }
            if (cur == q) {
                q_path.insert(q_path.end(), path.begin(), path.end());
                q_path.push_back(cur);
            }
            TreeNode *up = path.size() > 0 ? path.back() : nullptr;
            if (cur->left && prev == up) {
                prev = cur;
                path.push_back(cur);
                cur = cur->left;
            } else if (cur->right && (prev == up || prev == cur->left)) {
                prev = cur;
                path.push_back(cur);
                cur = cur->right;
            } else if (up != nullptr) {
                prev = cur;
                path.pop_back();
                cur = up;
            } else {
                break;
            }
        }
        int i = std::min(p_path.size(), q_path.size()) - 1;
        for (; i >= 0 && p_path[i] != q_path[i]; i--) {
        }
        return p_path[i];
    }
};
