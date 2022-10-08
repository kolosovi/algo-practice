// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int64_t n, res = 0;
  in >> n;
  for (int64_t div = 5; n / div >= 1; div *= 5) {
    res += n / div;
  }
  out << res << '\n';
}

int main() { Solve(std::cin, std::cout); }
