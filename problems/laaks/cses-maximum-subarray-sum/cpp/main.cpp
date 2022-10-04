// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int n, num;
  int64_t total = 0, min_total = 0, max = -1000000001;
  in >> n;
  while (n-- > 0) {
    in >> num;
    total += num;
    max = std::max(max, total - min_total);
    min_total = std::min(min_total, total);
  }
  out << max << '\n';
}

int main() { Solve(std::cin, std::cout); }
