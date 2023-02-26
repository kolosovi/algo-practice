// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <cstdint>
#include <istream>
#include <ostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  uint64_t n, target, max_latency = 0;
  in >> n >> target;
  std::vector<uint64_t> latencies(n);
  for (int i = 0; i < n; i++) {
    in >> latencies[i];
    max_latency = std::max(max_latency, latencies[i]);
  }
  uint64_t l = 1, r = max_latency * target;
  while (l <= r) {
    auto mid = l + (r - l) / 2;
    uint64_t products = 0;
    for (auto lat : latencies) {
      products += mid / lat;
      if (products >= target) {
        r = mid - 1;
        break;
      }
    }
    if (products < target) {
      l = mid + 1;
    }
  }
  out << l << '\n';
}

int main() { Solve(std::cin, std::cout); }
