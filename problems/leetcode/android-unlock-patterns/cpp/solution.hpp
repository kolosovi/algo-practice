#pragma once

#include <array>
#include <vector>

static const std::vector<std::vector<int>> bad_swipes{
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {1, 0, 0, 2, 0, 0, 0, 4, 0, 5},
    {2, 0, 0, 0, 0, 0, 0, 0, 5, 0}, {3, 2, 0, 0, 0, 0, 0, 5, 0, 6},
    {4, 0, 0, 0, 0, 0, 5, 0, 0, 0}, {5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {6, 0, 0, 0, 5, 0, 0, 0, 0, 0}, {7, 4, 0, 5, 0, 0, 0, 0, 0, 8},
    {8, 0, 5, 0, 0, 0, 0, 0, 0, 0}, {9, 5, 0, 6, 0, 0, 0, 8, 0, 0},
};

class Solution {
 public:
  Solution() : total(0), m(0), n(0), length(0), visited() { visited.fill(0); }

  int numberOfPatterns(int m, int n) {
    this->m = m, this->n = n;
    visit(-1);
    return total;
  }

  void visit(int last_dot) {
    if (length >= m && length <= n) {
      total++;
    }
    for (int next_dot = 1; next_dot <= 9; next_dot++) {
      if (visited[next_dot]) {
        continue;
      }
      if (last_dot != -1) {
        auto required_dot = bad_swipes[last_dot][next_dot];
        if (required_dot && !visited[required_dot]) {
          continue;
        }
      }
      visited[next_dot] = 1;
      length++;
      visit(next_dot);
      visited[next_dot] = 0;
      length--;
    }
  }

 private:
  int total, m, n, length;
  std::array<int, 10> visited;
};
