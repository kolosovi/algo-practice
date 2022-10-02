// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int64_t num;
  in >> num;
  out << num;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = (num * 3) + 1;
    }
    out << ' ' << num;
  }
  out << '\n';
}

int main() { Solve(std::cin, std::cout); }
