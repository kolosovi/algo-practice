#pragma once

#include <string>
#include <vector>

class Solution {
 public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<int> mem_row(text2.size(), -1);
    std::vector<std::vector<int>> mem(text1.size(), mem_row);
    return calc(text1, text2, mem, 0, 0);
  }

 private:
  int calc(const std::string &text1, const std::string &text2,
           std::vector<std::vector<int>> &mem, int l, int r) {
    if (l == text1.size() || r == text2.size()) {
      return 0;
    }
    if (mem[l][r] != -1) {
      return mem[l][r];
    }
    int result = 0;
    if (text1[l] == text2[r]) {
      result = 1 + calc(text1, text2, mem, l + 1, r + 1);
    } else {
      result = std::max({
          calc(text1, text2, mem, l + 1, r),
          calc(text1, text2, mem, l, r + 1),
      });
    }
    mem[l][r] = result;
    return result;
  }
};
