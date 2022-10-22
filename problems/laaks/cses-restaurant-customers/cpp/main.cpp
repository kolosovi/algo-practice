// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <cmath>
#include <istream>
#include <ostream>
#include <vector>

struct Compare {
  bool operator()(const int &lhs, const int &rhs) const {
    return std::abs(lhs) < std::abs(rhs);
  }
};

void Solve(std::istream &in, std::ostream &out) {
  int n, write_i = 0, count = 0, max = 0;
  in >> n;
  std::vector<int> times(2 * n);
  for (int i = 0; i < n; i++) {
    in >> times[write_i++];
    in >> times[write_i];
    times[write_i] = -times[write_i];
    write_i++;
  }
  std::sort(times.begin(), times.end(), Compare{});
  for (auto time : times) {
    if (time > 0) {
      count++;
    } else {
      count--;
    }
    max = std::max(max, count);
  }
  out << max << '\n';
}

int main() { Solve(std::cin, std::cout); }
