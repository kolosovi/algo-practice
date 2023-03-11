#pragma once

#include <istream>
#include <ostream>
#include <cstdint>
#include <unordered_map>

int64_t Abs(int64_t num) {
  if (num < 0) {
    return -num;
  }
  return num;
}

void Solve(std::istream &in, std::ostream &out) {
  int64_t n, number, sum = 0, result = 0;
  in >> n;
  std::unordered_map<int64_t, int64_t> mod_counts{{0, 1}};
  for (int i = 0; i < n; i++) {
    in >> number;
    sum = (sum + number % n) % n;
    int64_t sum_complement = (n - Abs(sum));
    if (sum > 0) {
      sum_complement = -sum_complement;
    }
    result += mod_counts[sum];
    if (sum_complement != sum) {
      result += mod_counts[sum_complement];
    }
    mod_counts[sum]++;
  }
  out << result << '\n';
}
