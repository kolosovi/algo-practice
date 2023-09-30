#pragma once

#include <vector>
#include <string>

static const std::vector<char> digits{'0', '1', '8', '6', '9'};
static const std::vector<char> stigid{'0', '1', '8', '9', '6'};

class Solution {
 public:
  std::vector<std::string> findStrobogrammatic(int n) {
    this->n = n;
    hc = n / 2 + n % 2;
    number.resize(hc);
    result.resize(0);
    solve(0);
    return result;
  }

  void solve(int i) {
    if (i == hc) {
      std::string num_string(n, 0);
      for (int offset = 0; offset < hc; ++offset) {
        num_string[offset] = digits[number[offset]];
        num_string[n - offset - 1] = stigid[number[offset]];
      }
      result.push_back(num_string);
      return;
    }
    int lb = 0, rb = digits.size();
    if (n != 1 && i == 0) {
      lb++;
    }
    if (n % 2 == 1 && i == hc - 1) {
      rb -= 2;
    }
    for (int j = lb; j < rb; ++j) {
      number[i] = j;
      solve(i + 1);
    }
  }

 private:
  int n, hc;
  std::vector<std::string> result;
  std::vector<int> number;
};
