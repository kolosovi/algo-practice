#pragma once

#include <istream>
#include <ostream>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int64_t n;
  in >> n;
  int64_t result = ((1 + n) * n) / 2, num;
  while (n-- > 1) {
    in >> num;
    result -= num;
  }
  out << result << '\n';
}
