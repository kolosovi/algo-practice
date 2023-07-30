#pragma once

#include <string>
#include <utility>

class Solution {
 public:
  std::string licenseKeyFormatting(std::string s, int k) {
    std::string result;
    result.reserve(s.size());
    int count = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      auto c = s[i];
      if (c == '-') {
        continue;
      }
      if (c >= 'a' && c <= 'z') {
        c -= ('a' - 'A');
      }
      if (count > 0 && count % k == 0) {
        result.push_back('-');
      }
      result.push_back(c);
      count++;
    }
    for (int i = 0; i < result.size() / 2; i++) {
      std::swap(result[i], result[result.size() - i - 1]);
    }
    return result;
  }
};
