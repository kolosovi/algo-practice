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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int max = 0;
        traverse(root, max, 0);
        return max;
    }

    int traverse(TreeNode *cur, int &max, int depth) {
        int left_depth = 0, right_depth = 0;
        if (cur->left != nullptr) {
            left_depth = traverse(cur->left, max, depth+1);
        }
        if (cur->right != nullptr) {
            right_depth = traverse(cur->right, max, depth+1);
        }
        max = std::max(max, left_depth + right_depth - depth - depth);
        if (left_depth == 0 && right_depth == 0) {
            return depth;
        }
        return std::max(left_depth, right_depth);
    }
};
