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

static const int kMaxUniqueNumbers = 6001;
static const int kOffset = 3000;

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::vector<int> map(kMaxUniqueNumbers);
        for (int pos = 0; pos < inorder.size(); pos++) {
            map[inorder[pos] + kOffset] = pos;
        }
        std::vector<TreeNode*> stack;
        TreeNode *root = new TreeNode(preorder.front());
        stack.emplace_back(root);
        for (int i = 1; i < preorder.size(); ++i) {
            auto top_pos = map[stack.back()->val + kOffset];
            auto pos = map[preorder[i] + kOffset];
            auto node = new TreeNode(preorder[i]);
            if (pos < top_pos) {
                stack.back()->left = node;
                stack.push_back(node);
                continue;
            }
            TreeNode *parent = nullptr;
            while (stack.size() > 0 && map[preorder[i] + kOffset] > map[stack.back()->val + kOffset]) {
                parent = stack.back();
                stack.pop_back();
            }
            parent->right = node;
            stack.push_back(node);
        }
        return root;
    }
};
