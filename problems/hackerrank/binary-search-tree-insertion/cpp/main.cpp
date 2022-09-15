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
  void preOrder(Node *root) {
    if (root == NULL) return;

    std::cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
  }

  /*
  Node is defined as

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

  */

  Node *insert(Node *root, int data) {
    auto *node = new Node(data);
    if (root == nullptr) {
      return node;
    }
    Node *cur = root;
    while (true) {
      if (data < cur->data) {
        if (cur->left == nullptr) {
          cur->left = node;
          break;
        }
        cur = cur->left;
      } else {
        if (cur->right == nullptr) {
          cur->right = node;
          break;
        }
        cur = cur->right;
      }
    }
    return root;
  }
};

int main() {
  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.preOrder(root);

  return 0;
}
