#pragma once

#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> result;
    std::vector<int> p_letter_freqs(26, 0), s_letter_freqs(26, 0);
    int matches_left = p_letter_freqs.size();
    for (auto letter : p) {
      p_letter_freqs[letter - 'a']++;
    }
    for (int i = 0; i < p_letter_freqs.size(); i++) {
      if (p_letter_freqs[i] == s_letter_freqs[i]) {
        matches_left--;
      }
    }
    int l = 0, r = 0;
    while (r < s.size()) {
      auto new_freq = ++s_letter_freqs[s[r] - 'a'];
      if (new_freq == p_letter_freqs[s[r] - 'a']) {
        matches_left--;
      } else if (new_freq == p_letter_freqs[s[r] - 'a'] + 1) {
        matches_left++;
      }
      r++;
      if (r - l > p.size()) {
        new_freq = --s_letter_freqs[s[l] - 'a'];
        if (new_freq == p_letter_freqs[s[l] - 'a']) {
          matches_left--;
        } else if (new_freq == p_letter_freqs[s[l] - 'a'] - 1) {
          matches_left++;
        }
        l++;
      }
      if (r - l == p.size() && matches_left == 0) {
        result.push_back(l);
      }
    }
    return result;
  }
};
