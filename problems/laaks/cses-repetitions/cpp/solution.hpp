#pragma once

#include <algorithm>
#include <istream>
#include <ostream>

void Solve(std::istream &in, std::ostream &out) {
  char ch, prev = '#';
  int max = 0, cur = 0;
  while (in >> ch) {
    if (ch != prev) {
      max = std::max(max, cur);
      cur = 1;
      prev = ch;
    } else {
      cur++;
    }
  }
  max = std::max(max, cur);
  out << max << '\n';
}
