#pragma once

#include <cstdint>
#include <string>
#include <vector>

class Solution {
 public:
  bool hasAllCodes(std::string s, int k) {
    uint32_t remaining_codes = (1 << k);
    uint32_t mask = remaining_codes - 1;
    std::vector<bool> has_code(remaining_codes, false);
    uint32_t code = 0;
    for (int i = 0; i < s.size(); i++) {
      code = mask & ((code << 1) | (s[i] - '0'));
      if (i >= k - 1 && !has_code[code]) {
        has_code[code] = true;
        remaining_codes--;
      }
    }
    return remaining_codes == 0;
  }
};
