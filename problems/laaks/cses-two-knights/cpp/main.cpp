// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>

void Solve(std::istream &in, std::ostream &out) {
  int64_t prev;
  int64_t n;
  in >> n;
  for (int64_t k = 1; k <= n; ++k) {
    if (k == 1) {
      out << 0 << '\n';
      continue;
    }
    if (k == 2) {
      out << 6 << '\n';
      continue;
    }
    if (k == 3) {
      out << 28 << '\n';
      prev = 28;
      continue;
    }
    auto k2 = k * k;
    prev = 3 * (k2 - 3) + 4 * (k2 - 4) + 2 * (k - 4) * (k2 - 5) -
           ((2 * k - 1) * (2 * k - 2)) / 2 + 2 + prev;
    out << prev << '\n';
  }
}

int main() { Solve(std::cin, std::cout); }
