#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
 public:
  std::vector<std::vector<int>> palindromePairs(
      std::vector<std::string>& words) {
    std::vector<std::vector<int>> result;
    std::unordered_map<std::string, int> lookup;
    std::unordered_map<std::string, int> rev_lookup;
    for (int i = 0; i < words.size(); ++i) {
      lookup.emplace(words[i], i);
    }
    for (int i = 0; i < words.size(); ++i) {
      for (int l = 0, r = words[i].size() - 1; l < r; l++, r--) {
        std::swap(words[i][l], words[i][r]);
      }
      rev_lookup.emplace(words[i], i);
    }
    for (int j = 0; j < words.size(); ++j) {
      std::string prefix;
      for (int i = words[j].size(); i >= 0; i--) {
        if (i < words[j].size()) {
          prefix.push_back(words[j][i]);
        }
        auto it = rev_lookup.find(prefix);
        if (it == rev_lookup.end()) {
          continue;
        }
        if (it->second == j) {
          continue;
        }
        if (IsPalindromic(words[j], 0, i - 1)) {
          result.push_back({j, it->second});
        }
      }
      std::string rev_suffix;
      for (int i = -1; i < 0 || i < words[j].size(); i++) {
        if (i >= 0) {
          rev_suffix.push_back(words[j][i]);
        }
        auto it = lookup.find(rev_suffix);
        if (it == lookup.end()) {
          continue;
        }
        if (it->second == j) {
          continue;
        }
        if (i != words[j].size() - 1 &&
            IsPalindromic(words[j], i + 1, words[j].size() - 1)) {
          result.push_back({it->second, j});
        }
      }
    }
    return result;
  }

 private:
  bool IsPalindromic(const std::string& word, int l, int r) {
    for (; l < r; l++, r--) {
      if (word[l] != word[r]) {
        break;
      }
    }
    return l >= r;
  }
};
