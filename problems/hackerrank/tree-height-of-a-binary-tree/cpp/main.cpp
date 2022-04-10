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
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        std::vector<Node*> path;
        Node *prev = nullptr;
        auto *cur = root;
        int h = 0;
        while (cur != nullptr) {
            h = std::max(h, int(path.size()));
            Node *up = nullptr;
            if (path.size() > 0) {
                up = path.back();
            }
            if (cur->left != nullptr && prev == up) {
                path.push_back(cur);
                prev = cur;
                cur = cur->left;
            } else if (cur->right != nullptr && (prev == up || prev == cur->left)) {
                path.push_back(cur);
                prev = cur;
                cur = cur->right;
            } else {
                prev = cur;
                cur = up;
                if (path.size() > 0) {
                    path.pop_back();
                }
            }
        }
        return h;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}
