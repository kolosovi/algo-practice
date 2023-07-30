#pragma once

#include <istream>
#include <ostream>

void Solve(std::istream &in, std::ostream &out) {
  int num;
  in >> num;
  if (num != 0 && num % 10 == 0) {
    out << "false\n";
  } else {
    out << "true\n";
  }
}
