#pragma once

#include <istream>
#include <ostream>
#include <cstdint>

static constexpr int64_t kModulus = 1000000007;

int64_t pow(int64_t n) {
  if (n == 0) {
    return 1;
  }
  int64_t half_n = n / 2;
  int64_t mul = n % 2 == 1 ? 2 : 1;
  auto half_pow = pow(half_n);
  return (half_pow * half_pow * mul) % kModulus;
}

void Solve(std::istream &in, std::ostream &out) {
  int64_t n;
  in >> n;
  out << pow(n) << '\n';
}
