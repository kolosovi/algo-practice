// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <istream>
#include <ostream>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int64_t n, num, max = 0, result = 0;
  in >> n;
  while (n-- > 0) {
    in >> num;
    if (num < max) {
      result += max - num;
    }
    max = std::max(max, num);
  }
  out << result << '\n';
}

int main() { Solve(std::cin, std::cout); }
