#pragma once

#include <algorithm>
#include <istream>
#include <ostream>
#include <vector>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> lens(n);
  for (int i = 0; i < n; i++) {
    in >> lens[i];
  }
  std::sort(lens.begin(), lens.end());
  int64_t ltotal = 0, rtotal = 0;
  for (int i = 1; i < n; i++) {
    rtotal += lens[i] - lens[0];
  }
  int64_t result = rtotal;
  for (int i = 0; i < n; i++) {
    int64_t diff = i == 0 ? 0 : lens[i] - lens[i - 1];
    ltotal += diff * i;
    rtotal -= diff * (n - i);
    result = std::min(result, ltotal + rtotal);
  }
  out << result << '\n';
}
