#pragma once

#include <vector>
#include <string>
#include <algorithm>

class Solution {
 public:
  int findMaxForm(std::vector<std::string> &strs, int m, int n) {
    std::vector<int> memo_2(n + 1, -1);
    std::vector<std::vector<int>> memo_1(m + 1, memo_2);
    std::vector<std::vector<std::vector<int>>> memo(strs.size() + 1, memo_1);
    return calculate(strs, memo, 0, m, n);
  }

  int calculate(std::vector<std::string> &strs,
                std::vector<std::vector<std::vector<int>>> &memo, int i, int m,
                int n) {
    if (i == strs.size()) {
      return 0;
    }
    if (memo[i][m][n] != -1) {
      return memo[i][m][n];
    }
    int max = 0;
    max = std::max(max, calculate(strs, memo, i + 1, m, n));
    auto zero_count = std::count(strs[i].begin(), strs[i].end(), '0');
    auto one_count = std::count(strs[i].begin(), strs[i].end(), '1');
    if (zero_count <= m && one_count <= n) {
      max = std::max(
          max, 1 + calculate(strs, memo, i + 1, m - zero_count, n - one_count));
    }
    memo[i][m][n] = max;
    return max;
  }
};
