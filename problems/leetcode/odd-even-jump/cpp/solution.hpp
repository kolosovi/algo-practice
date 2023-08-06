#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

static constexpr int kNoJump = -1;

void fill_jumps(std::vector<int> &jumps, const std::vector<int> &positions) {
  std::vector<int> stack;
  stack.push_back(positions.back());
  for (int i = positions.size() - 2; i >= 0; i--) {
    auto pos = positions[i];
    auto jump_pos_it = std::lower_bound(stack.rbegin(), stack.rend(), pos);
    if (jump_pos_it != stack.rend()) {
      jumps[pos] = *jump_pos_it;
    }
    while (stack.size() > 0 && pos > stack.back()) {
      stack.pop_back();
    }
    stack.push_back(pos);
  }
}

std::vector<int> calc_odd_jumps(const std::vector<int> &arr) {
  std::vector<int> odd_jumps(arr.size(), kNoJump);
  std::vector<int> positions(arr.size());
  std::iota(positions.begin(), positions.end(), 0);
  std::sort(positions.begin(), positions.end(),
            [&arr](const int &i, const int &j) {
              return arr[i] == arr[j] ? i < j : arr[i] < arr[j];
            });
  fill_jumps(odd_jumps, positions);
  return odd_jumps;
}

std::vector<int> calc_even_jumps(const std::vector<int> &arr) {
  std::vector<int> even_jumps(arr.size(), kNoJump);
  std::vector<int> positions(arr.size());
  std::iota(positions.begin(), positions.end(), 0);
  std::sort(positions.begin(), positions.end(),
            [&arr](const int &i, const int &j) {
              return arr[i] == arr[j] ? i < j : arr[i] > arr[j];
            });
  fill_jumps(even_jumps, positions);
  return even_jumps;
}

class Solution {
 public:
  int oddEvenJumps(std::vector<int> &arr) {
    auto odd_jumps = calc_odd_jumps(arr);
    auto even_jumps = calc_even_jumps(arr);
    std::vector<bool> is_good(arr.size(), false);
    std::vector<bool> is_evengood(arr.size(), false);
    is_good[arr.size() - 1] = true;
    is_evengood[arr.size() - 1] = true;
    int good_count = 1;
    for (int i = arr.size() - 2; i >= 0; i--) {
      auto odd_jump = odd_jumps[i];
      auto even_jump = even_jumps[i];
      if (odd_jump != kNoJump && is_evengood[odd_jump]) {
        good_count++;
        is_good[i] = true;
      }
      if (even_jump != kNoJump && is_good[even_jump]) {
        is_evengood[i] = true;
      }
    }
    return good_count;
  }
};
