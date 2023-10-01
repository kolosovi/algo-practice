#pragma once

#include <vector>
#include <string>

class Solution {
 public:
  Solution() : pattern({}), result({}) {}

  std::vector<std::string> generateParenthesis(int n) {
    add_next(n, 0);
    return result;
  }

  void add_next(int open_count, int close_count) {
    if (open_count > 0) {
      pattern.push_back('(');
      add_next(open_count - 1, close_count + 1);
      pattern.pop_back();
    }
    if (close_count > 0) {
      pattern.push_back(')');
      add_next(open_count, close_count - 1);
      pattern.pop_back();
    }
    if (open_count == 0 && close_count == 0) {
      result.push_back(pattern);
    }
  }

 private:
  std::string pattern;
  std::vector<std::string> result;
};
