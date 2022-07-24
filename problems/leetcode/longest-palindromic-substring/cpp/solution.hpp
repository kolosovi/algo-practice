#pragma once

#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int max_len = 0, max_start;
        for (int center_start = 0; center_start < s.size(); center_start++) {
            for (int center_end = center_start; center_end <= center_start + 1 && center_end < s.size(); center_end++) {
                int start = center_start, end = center_end;
                while (start >= 0 && end < s.size() && s[start] == s[end]) {
                    int len = end - start + 1;
                    if (len > max_len) {
                        max_len = len;
                        max_start = start;
                    }
                    start--;
                    end++;
                }
            }
        }
        return s.substr(max_start, max_len);
    }
};
