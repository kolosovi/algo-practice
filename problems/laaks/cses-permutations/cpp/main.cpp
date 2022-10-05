// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  if (n == 1) {
    out << "1\n";
    return;
  }
  if (n <= 3) {
    out << "NO SOLUTION\n";
    return;
  }
  if (n == 4) {
    out << "2 4 1 3\n";
    return;
  }
  for (int i = 1; i <= n; i += 2) {
    out << i << ' ';
  }
  for (int i = 2; i <= n; i += 2) {
    out << i;
    if (i + 2 <= n) {
      out << ' ';
    }
  }
  out << '\n';
}

int main() { Solve(std::cin, std::cout); }
