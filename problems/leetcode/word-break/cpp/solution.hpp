#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    std::unordered_set<std::string> dict;
    for (auto &word : wordDict) {
      dict.insert(std::move(word));
    }
    std::vector<int> mem(s.size(), -1);
    return wordBreak(s, dict, mem, 0);
  }

  bool wordBreak(const std::string &s,
                 const std::unordered_set<std::string> &dict,
                 std::vector<int> &mem, int start) {
    if (mem[start] != -1) {
      return mem[start] == 1;
    }
    std::string prefix;
    for (int i = start; i < s.size(); i++) {
      prefix.push_back(s[i]);
      if (!dict.count(prefix)) {
        continue;
      }
      if (i == s.size() - 1 || wordBreak(s, dict, mem, i + 1)) {
        mem[start] = 1;
        return true;
      }
    }
    mem[start] = 0;
    return false;
  }
};
