#pragma once

#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> chars;
        int start = 0, end = 0, max = 0;
        while (end < s.size()) {
            auto it = chars.find(s[end]);
            if (it == chars.end()) {
                chars.insert(s[end]);
                end++;
            } else {
                for (; start < end;) {
                    chars.erase(s[start++]);
                    if (s[start-1] == s[end]) {
                        break;
                    }
                }
            }
            max = std::max(max, end - start);
        }
        return max;
    }
};
