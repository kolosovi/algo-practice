#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(std::string s) {
    std::unordered_map<char, int> char_to_max_i;
    // invariant: left points at the first char in window, right points
    // past the end of window
    int left = 0, right = 0, max_len = -1;
    // invariant: on the start of each loop, right either points to a valid
    // index or it points past the end and there are characters to pop off
    while (right < s.size() ||
           (right == s.size() && char_to_max_i.size() > 2)) {
      if (char_to_max_i.size() <= 2) {
        max_len = std::max(max_len, right - left);
        char_to_max_i[s[right]] = right;
        right++;
        continue;
      }
      int min_max_i = s.size();
      char char_to_remove;
      for (auto [a_char, a_max_i] : char_to_max_i) {
        if (a_max_i < min_max_i) {
          min_max_i = a_max_i;
          char_to_remove = a_char;
        }
      }
      left = min_max_i + 1;
      char_to_max_i.erase(char_to_remove);
    }
    // at the end of the loop, the loop condition does not hold, from this
    // it follows that window is "good" => we must update max_len
    max_len = std::max(max_len, right - left);
    return max_len;
  }
};
