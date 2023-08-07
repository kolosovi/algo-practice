#pragma once

#include <string>

static constexpr int kAlphabetSize = 52;

inline int index(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c - 'A';
  }
  return (kAlphabetSize / 2) + (c - 'a');
}

class Acc {
 public:
  Acc(const std::string &t) {
    match_count_ = kAlphabetSize;
    for (int i = 0; i < kAlphabetSize; i++) {
      freq_[i] = 0;
      target_freq_[i] = 0;
    }
    for (auto c : t) {
      auto idx = index(c);
      target_freq_[idx]++;
      if (target_freq_[idx] == freq_[idx] + 1) {
        match_count_--;
      }
    }
  }

  void Add(char c) {
    auto idx = index(c);
    freq_[idx]++;
    if (freq_[idx] == target_freq_[idx]) {
      match_count_++;
    }
  }

  void Remove(char c) {
    auto idx = index(c);
    freq_[idx]--;
    if (freq_[idx] == target_freq_[idx] - 1) {
      match_count_--;
    }
  }

  bool Matches() const { return match_count_ == kAlphabetSize; }

 private:
  int freq_[kAlphabetSize];
  int target_freq_[kAlphabetSize];
  int match_count_;
};

class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    Acc acc(t);
    int left = 0, right = 0, min_left = -1, min_right = -1, min = s.size() + 1;
    while (right < s.size() || (right == s.size() && left < right)) {
      if (acc.Matches()) {
        auto len = right - left;
        if (len < min) {
          min = len;
          min_left = left;
          min_right = right;
        }
        acc.Remove(s[left++]);
      } else {
        if (right < s.size()) {
          acc.Add(s[right++]);
        } else {
          break;
        }
      }
    }
    if (min_left == -1) {
      return {};
    }
    return s.substr(min_left, min_right - min_left);
  }
};
