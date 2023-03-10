// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <vector>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int n, target, result = 0;
  in >> n >> target;
  std::vector<int64_t> left_sums(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    in >> left_sums[i];
    left_sums[i] += left_sums[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    int64_t want = left_sums[i] - target;
    int l = 0, r = i;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (left_sums[m] == want) {
        result++;
        break;
      }
      if (want < left_sums[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
  }
  out << result << '\n';
}

int main() { Solve(std::cin, std::cout); }
