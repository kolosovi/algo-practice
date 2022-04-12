// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return root;
        }
        traverse(root);
        if (first_ != nullptr && last_ != nullptr) {
            first_->left = last_;
            last_->right = first_;
        }
        return first_;
    }

private:
    Node* first_;
    Node* last_;

    void traverse(Node* node) {
        if (node->left != nullptr) {
            traverse(node->left);
        }

        if (first_ == nullptr) {
            first_ = node;
        }
        if (last_ != nullptr) {
            last_->right = node;
        }
        node->left = last_;
        last_ = node;

        if (node->right != nullptr) {
            traverse(node->right);
        }
    }
};
