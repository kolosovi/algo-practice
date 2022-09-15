#pragma once

#include <vector>
#include <unordered_map>

class Node {
 public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    std::unordered_map<int, Node*> memo;
    return cloneGraph(memo, node);
  }

 private:
  Node* cloneGraph(std::unordered_map<int, Node*>& memo, Node* old_node) {
    auto memo_it = memo.find(old_node->val);
    if (memo_it != memo.end()) {
      return memo_it->second;
    }
    auto new_node = new Node(old_node->val, {});
    memo.insert({old_node->val, new_node});
    for (auto old_neighbor : old_node->neighbors) {
      new_node->neighbors.push_back(cloneGraph(memo, old_neighbor));
    }
    return new_node;
  }
};
