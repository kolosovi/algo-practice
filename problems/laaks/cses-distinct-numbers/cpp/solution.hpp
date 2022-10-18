#pragma once

#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>

void Solve(std::istream &in, std::ostream &out) {
  int n, count = 0;
  in >> n;
  std::vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) {
    in >> nums[i];
  }
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++) {
    if (i == 0 || nums[i] != nums[i - 1]) {
      count++;
    }
  }
  out << count << '\n';
}
