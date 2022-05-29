#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cstdint>

class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        std::unordered_map<std::uint32_t, int> max_lengths;
        for (int i = 0; i < words.size(); i++) {
            uint32_t key = 0;
            for (auto ch : words[i]) {
                key |= (1 << (ch - 'a'));
            }
            max_lengths[key] = std::max(max_lengths[key], static_cast<int>(words[i].size()));
        }
        int result = 0;
        for (auto [k1, max_len1] : max_lengths) {
            for (auto [k2, max_len2] : max_lengths) {
                if ((k1 & k2) == 0) {
                    result = std::max(result, max_len1 * max_len2);
                }
            }
        }
        return result;
    }
};
