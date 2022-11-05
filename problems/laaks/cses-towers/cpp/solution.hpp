#pragma once

#include <algorithm>
#include <istream>
#include <ostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  int n, cube;
  in >> n;
  std::vector<int> tops;
  while (n-- > 0) {
    in >> cube;
    auto gt_it = std::upper_bound(tops.begin(), tops.end(), cube);
    if (gt_it == tops.end()) {
      tops.push_back(cube);
      continue;
    }
    *gt_it = cube;
  }
  out << tops.size() << '\n';
}
