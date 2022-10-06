#pragma once

#include <istream>
#include <ostream>

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  if (n % 4 != 0 && (n + 1) % 4 != 0) {
    out << "NO\n";
    return;
  }
  out << "YES\n";
  out << (n / 2) + (n % 2) << '\n';
  int i = n;
  for (; i - 4 >= 0; i -= 4) {
    out << i << ' ' << i - 3;
    if (i - 4 >= 3) {
      out << ' ';
    }
  }
  if (i > 0) {
    out << "2 1";
  }
  out << '\n';
  out << n / 2 << '\n';
  for (i = n; i - 4 >= 0; i -= 4) {
    out << i - 1 << ' ' << i - 2;
    if (i - 4 >= 3) {
      out << ' ';
    }
  }
  if (i > 0) {
    out << "3";
  }
  out << '\n';
}
