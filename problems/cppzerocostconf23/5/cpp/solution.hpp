#pragma once

#include <istream>
#include <ostream>

static constexpr char *kLookupTable = "YANDEXTAXI";

void Solve(std::istream &in, std::ostream &out) {
  char c;
  while (in.get(c)) {
    if (c < '0' || c > '9') {
      out << c;
      continue;
    }
    out << (kLookupTable[c - '0']);
  }
  out << std::endl;
}
