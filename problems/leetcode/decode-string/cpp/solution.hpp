#pragma once

#include <sstream>
#include <string>

class Solution {
 public:
  std::string decodeString(std::string s) {
    i_ = 0;
    return decode(s);
  }

 private:
  int i_;

  std::string decode(const std::string &s) {
    std::stringstream buf;
    int sub_count = 0;
    for (; i_ < s.size(); i_++) {
      if (s[i_] >= 'a' && s[i_] <= 'z') {
        buf << s[i_];
      } else if (s[i_] >= '0' && s[i_] <= '9') {
        sub_count = 10 * sub_count + (s[i_] - '0');
      } else if (s[i_] == '[') {
        i_++;
        auto sub = decode(s);
        for (; sub_count > 0; sub_count--) {
          buf << sub;
        }
      } else {  // closing ]
        return buf.str();
      }
    }
    return buf.str();
  }
};
