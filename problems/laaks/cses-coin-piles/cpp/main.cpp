// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <cstdint>
#include <utility>

void Solve(std::istream &in, std::ostream &out) {
  int64_t t, a, b;
  in >> t;
  while (t-- > 0) {
    in >> a >> b;
    if (b > a) {
      std::swap(a, b);
    }
    a -= 2 * (a - b);
    out << ((a >= 0 && a % 3 == 0) ? "YES" : "NO") << '\n';
  }
}

int main() { Solve(std::cin, std::cout); }
