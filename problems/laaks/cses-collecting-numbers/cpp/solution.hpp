#pragma once

#include <istream>
#include <ostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  int n, num, count = 0;
  in >> n;
  std::vector<int> indexes(n, 0);
  for (int i = 0; i < n; i++) {
    in >> num;
    indexes[num - 1] = i;
  }
  for (int i = 0; i < indexes.size(); i++) {
    if (i == 0 || indexes[i] < indexes[i - 1]) {
      count++;
    }
  }
  out << count << '\n';
}
