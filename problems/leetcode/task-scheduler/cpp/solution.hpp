#pragma once

#include <vector>
#include <algorithm>

class Solution {
 public:
  int leastInterval(std::vector<char>& tasks, int n) {
    std::vector<int> freqs(26, 0);
    for (const auto& task : tasks) {
      freqs[task - 'A']++;
    }
    std::sort(freqs.begin(), freqs.end());
    auto idle_slots = n * (freqs.back() - 1);
    for (auto it = std::next(freqs.rbegin());
         it != freqs.rend() && idle_slots > 0; ++it) {
      idle_slots -= std::min(*it, freqs.back() - 1);
    }
    return tasks.size() + std::max(0, idle_slots);
  }
};
