#pragma once

#include <vector>

class Solution {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    int carry = 0;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      if (*it < 9) {
        (*it)++;
        break;
      }
      *it = 0;
    }
    std::vector<int> result(digits.size(), 0);
    int i = 0;
    if (digits[0] == 0) {
      result.resize(result.size() + 1);
      result[i++] = 1;
    }
    for (auto digit : digits) {
      result[i++] = digit;
    }
    return result;
  }
};
