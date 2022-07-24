#pragma once

#include <string>
#include <vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::vector<bool> mem_row(s.size(), false);
        std::vector<std::vector<bool>> mem(s.size(), mem_row);
        int max_len = 0, max_start;
        for (int len = 1; len <= s.size(); ++len) {
            for (int start = 0; start <= s.size() - len; ++start) {
                int end = start + len - 1;
                if (s[start] != s[end] || len > 2 && !mem[start+1][end-1]) {
                    continue;
                }
                mem[start][end] = true;
                if (len > max_len) {
                    max_len = len;
                    max_start = start;
                }
            }
        }
        return s.substr(max_start, max_len);
    }
};
