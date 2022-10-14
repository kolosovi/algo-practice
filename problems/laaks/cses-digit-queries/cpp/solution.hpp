#pragma once

#include <istream>
#include <ostream>
#include <cstdint>

static constexpr int kLimit = 18;

static uint64_t kPowers[kLimit];
static uint64_t kNumCounts[kLimit];
static uint64_t kDigitCounts[kLimit];

void solve(std::ostream &out, uint64_t k) {
  int width = 0;
  for (; width < kLimit && kDigitCounts[width] < k; width++) {
  }
  auto offset = k - kDigitCounts[width - 1] - 1;
  auto number = kPowers[width - 1] + (offset / width);
  auto digit_idx = offset % width;
  uint64_t result = 0;
  int count = width - digit_idx;
  while (count-- > 0) {
    result = number % 10;
    number = number / 10;
  }
  out << result << '\n';
}

void Solve(std::istream &in, std::ostream &out) {
  kPowers[0] = 1;
  kNumCounts[0] = kDigitCounts[0] = 0;
  for (uint64_t width = 1; width < kLimit; width++) {
    kPowers[width] = kPowers[width - 1] * 10;
    uint64_t num_count_diff = 9 * kPowers[width - 1];
    kNumCounts[width] = kNumCounts[width - 1] + num_count_diff;
    kDigitCounts[width] = kDigitCounts[width - 1] + width * num_count_diff;
  }
  int q;
  in >> q;
  while (q-- > 0) {
    uint64_t k;
    in >> k;
    solve(out, k);
  }
}
