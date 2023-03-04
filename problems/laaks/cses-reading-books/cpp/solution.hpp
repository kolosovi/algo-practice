#pragma once

#include <istream>
#include <ostream>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int64_t n, total = 0, max = 0, num = 0;
  in >> n;
  for (int i = 0; i < n; i++) {
    in >> num;
    total += num;
    if (num > max) {
      max = num;
    }
  }
  if (max >= total - max) {
    out << 2 * max << '\n';
  } else {
    out << total << '\n';
  }
}
