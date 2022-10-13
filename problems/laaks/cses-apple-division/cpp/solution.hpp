#pragma once

#include <cstring>
#include <istream>
#include <ostream>
#include <vector>

void solve(std::vector<int> &weights, int64_t &diff, int64_t &min,
           std::size_t i) {
  if (i == weights.size()) {
    min = std::min(min, std::abs(diff));
    return;
  }
  solve(weights, diff, min, i + 1);
  diff -= 2 * weights[i];
  solve(weights, diff, min, i + 1);
  diff += 2 * weights[i];
}

void Solve(std::istream &in, std::ostream &out) {
  int64_t n, diff = 0;
  in >> n;
  std::vector<int> weights(n, 0);
  for (int i = 0; i < n; i++) {
    in >> weights[i];
    diff += weights[i];
  }
  int64_t min = diff;
  solve(weights, diff, min, 0);
  out << min << '\n';
}
