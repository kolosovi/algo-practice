// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <cstdint>
#include <istream>
#include <ostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<uint64_t> nums(n);
  for (int i = 0; i < n; i++) {
    in >> nums[i];
  }
  std::sort(nums.begin(), nums.end());
  uint64_t sum = 0;
  for (int i = 0; i < n && nums[i] <= sum + 1; i++) {
    sum += nums[i];
  }
  out << sum + 1 << '\n';
}

int main() { Solve(std::cin, std::cout); }
