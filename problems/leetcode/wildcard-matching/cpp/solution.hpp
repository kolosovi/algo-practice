#pragma once

#include <string>

static constexpr char kQuestion = '?';
static constexpr char kStar = '*';

static constexpr char kNotFound = -1;
static constexpr char kFalse = 0;
static constexpr char kTrue = 1;

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    std::vector<char> mem_row(p.size() + 1, kNotFound);
    std::vector<std::vector<char>> mem(s.size() + 1, mem_row);
    mem[s.size()][p.size()] = kTrue;
    return solve(s, p, mem, 0, 0);
  }

 private:
  bool solve(const std::string &s, const std::string &p,
             std::vector<std::vector<char>> &mem, int i, int j) {
    if (mem[i][j] != kNotFound) {
      return mem[i][j];
    }
    if (j == p.size()) {
      return i == s.size();
    }
    int result = kFalse;
    if (p[j] != kStar) {
      if (i == s.size()) {
        return false;
      }
      if (p[j] == kQuestion || s[i] == p[j]) {
        result = solve(s, p, mem, i + 1, j + 1);
      }
    } else {
      for (int rest_start = i; rest_start <= s.size(); ++rest_start) {
        if (solve(s, p, mem, rest_start, j + 1)) {
          result = kTrue;
        }
      }
    }
    mem[i][j] = result;
    return result;
  }
};
