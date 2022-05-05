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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return flipEquivRec(root1, root2);
    }

    bool flipEquivRec(TreeNode* cur1, TreeNode *cur2) {
        // both have no children
        if (cur1->left == nullptr && cur1->right == nullptr
                && cur2->left == nullptr && cur2->right == nullptr) {
            return true;
        }

        // only one has no children
        if (cur1->left == nullptr && cur1->right == nullptr
                    || cur2->left == nullptr && cur2->right == nullptr) {
            return false;
        }

        // both have at least one child, store it in first_child_*
        auto *first_child_1 = cur1->left != nullptr ? cur1->left : cur1->right;
        auto *second_child_1 = cur1->left != first_child_1 ? cur1->left : cur1->right;
        auto *first_child_2 = cur2->left != nullptr ? cur2->left : cur2->right;
        auto *second_child_2 = cur2->left != first_child_2 ? cur2->left : cur2->right;
        
        // they have unequal numbers of children (1 & 2 or 2 & 1)
        if ((second_child_1 != nullptr && second_child_2 == nullptr)
                || (second_child_2 != nullptr && second_child_1 == nullptr)) {
            return false;
        }

        // both have only one child
        if (second_child_1 == nullptr) {
            if (first_child_1->val != first_child_2->val) {
                return false;
            }
            return flipEquivRec(first_child_1, first_child_2);
        }

        // both have two children
        // flip children if first children of two nodes don't match
        if (first_child_1->val != first_child_2->val) {
            std::swap(first_child_2, second_child_2);
        }
        // still no match — exit
        if (first_child_1->val != first_child_2->val || second_child_1->val != second_child_2->val) {
            return false;
        }
        // there's a match, check children recursively
        return flipEquivRec(first_child_1, first_child_2) && flipEquivRec(second_child_1, second_child_2);
    }
};
