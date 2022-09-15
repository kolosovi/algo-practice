#pragma once

#include <vector>
#include <utility>

class Solution {
 public:
  std::vector<int> findMinHeightTrees(int n,
                                      std::vector<std::vector<int>> &edges) {
    if (n == 1) {
      return {0};
    }
    std::vector<std::vector<int>> children(n, std::vector<int>{});
    for (auto pair : edges) {
      children[pair[0]].push_back(pair[1]);
      children[pair[1]].push_back(pair[0]);
    }
    int max_node_1, max_node_2, diameter = 0;
    dfs1(0, children, -1, 0, max_node_1, diameter);
    dfs1(max_node_1, children, -1, 0, max_node_2, diameter);
    int target_depth = (diameter / 2) + (diameter % 2);
    std::vector<int> result;
    dfs2(max_node_2, children, result, -1, 0, target_depth, diameter);
    return result;
  }

 private:
  void dfs1(int node, const std::vector<std::vector<int>> &children, int parent,
            int depth, int &max_node, int &diameter) {
    if (depth >= diameter) {
      diameter = depth;
      max_node = node;
    }
    for (auto child : children[node]) {
      if (child != parent) {
        dfs1(child, children, node, depth + 1, max_node, diameter);
      }
    }
  }

  bool dfs2(int node, const std::vector<std::vector<int>> &children,
            std::vector<int> &result, int parent, int depth, int target_depth,
            int diameter) {
    if (depth == diameter) {
      if (depth == target_depth ||
          (diameter % 2 == 1 && depth == target_depth - 1)) {
        result.push_back(node);
      }
      return true;
    }
    for (auto child : children[node]) {
      if (child == parent) {
        continue;
      }
      if (dfs2(child, children, result, node, depth + 1, target_depth,
               diameter)) {
        if (depth == target_depth ||
            (diameter % 2 == 1 && depth == target_depth - 1)) {
          result.push_back(node);
        }
        return true;
      }
    }
    return false;
  }
};
