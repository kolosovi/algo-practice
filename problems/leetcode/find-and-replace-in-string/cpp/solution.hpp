#pragma once

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

bool substring_equal(const std::string &source, int source_offset,
                     const std::string &target) {
  if (source_offset >= source.size()) {
    return false;
  }
  for (int i = 0; i < target.size(); i++) {
    if (source_offset + i >= source.size()) {
      return false;
    }
    if (source[source_offset + i] != target[i]) {
      return false;
    }
  }
  return true;
}

class Solution {
 public:
  std::string findReplaceString(std::string s, std::vector<int> &indices,
                                std::vector<std::string> &sources,
                                std::vector<std::string> &targets) {
    int target_size = s.size(), k = indices.size();
    for (int i = 0; i < k; i++) {
      if (targets[i].size() > sources[i].size()) {
        target_size += targets[i].size();
        target_size -= sources[i].size();
      }
    }
    std::string target(target_size, '\0');
    std::vector<int> order(k);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(),
              [&indices](const int &x, const int &y) {
                return indices[x] < indices[y];
              });
    int read_i = 0, write_i = 0;
    auto order_it = order.begin();
    while (read_i < s.size()) {
      if (order_it == order.end() || read_i < indices[*order_it]) {
        target[write_i] = s[read_i];
        write_i++;
        read_i++;
        continue;
      }
      if (substring_equal(s, read_i, sources[*order_it])) {
        for (int i = 0; i < targets[*order_it].size(); i++) {
          target[write_i] = targets[*order_it][i];
          write_i++;
        }
        read_i += sources[*order_it].size();
      }
      order_it = std::next(order_it);
    }
    target.resize(write_i);
    return target;
  }
};
