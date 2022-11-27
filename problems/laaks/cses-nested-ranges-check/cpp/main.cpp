// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <istream>
#include <ostream>
#include <utility>
#include <vector>
#include <numeric>

void Solve(std::istream &in, std::ostream &out) {
  int num_ranges;
  in >> num_ranges;
  std::vector<std::pair<int, int>> ranges(num_ranges);
  std::vector<int> ixes(num_ranges);
  std::iota(ixes.begin(), ixes.end(), 0);
  std::vector<bool> contains(num_ranges, false),
      is_contained(num_ranges, false);
  for (int i = 0; i < num_ranges; i++) {
    in >> ranges[i].first >> ranges[i].second;
  }

  // sort by end ASC, start DESC
  std::sort(ixes.begin(), ixes.end(),
            [&ranges](const int &lhs, const int &rhs) -> bool {
              if (ranges[lhs].second == ranges[rhs].second) {
                return ranges[lhs].first > ranges[rhs].first;
              }
              return ranges[lhs].second < ranges[rhs].second;
            });

  int max_finished_i = -1;
  for (auto i : ixes) {
    if (max_finished_i >= 0 &&
        ranges[max_finished_i].first >= ranges[i].first) {
      contains[i] = true;
    }
    if (max_finished_i == -1 ||
        ranges[i].first > ranges[max_finished_i].first) {
      max_finished_i = i;
    }
  }

  // sort by start ASC, end DESC
  std::sort(ixes.begin(), ixes.end(),
            [&ranges](const int &lhs, const int &rhs) -> bool {
              if (ranges[lhs].first == ranges[rhs].first) {
                return ranges[lhs].second > ranges[rhs].second;
              }
              return ranges[lhs].first < ranges[rhs].first;
            });

  max_finished_i = -1;
  for (auto i : ixes) {
    if (max_finished_i >= 0 &&
        ranges[max_finished_i].second >= ranges[i].second) {
      is_contained[i] = true;
    }
    if (max_finished_i == -1 ||
        ranges[i].second > ranges[max_finished_i].second) {
      max_finished_i = i;
    }
  }

  for (int i = 0; i < num_ranges; i++) {
    out << contains[i] << (i < num_ranges - 1 ? ' ' : '\n');
  }
  for (int i = 0; i < num_ranges; i++) {
    out << is_contained[i] << (i < num_ranges - 1 ? ' ' : '\n');
  }
}

int main() { Solve(std::cin, std::cout); }
