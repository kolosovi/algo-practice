#pragma once

#include <istream>
#include <ostream>
#include <cstdint>
#include <algorithm>

void Solve(std::istream &in, std::ostream &out) {
  int64_t t, row, col;
  in >> t;
  while (t-- > 0) {
    in >> row >> col;
    auto max = std::max(row, col);
    int64_t res = (max - 1) * (max - 1);
    if (max % 2 == 1) {
      if (row >= col) {
        res += col;
      } else {
        res += 2 * max - row;
      }
    } else {
      if (row >= col) {
        res += 2 * max - col;
      } else {
        res += row;
      }
    }
    out << res << '\n';
  }
}
