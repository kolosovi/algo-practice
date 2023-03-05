#pragma once

#include <algorithm>
#include <cstdint>
#include <istream>
#include <ostream>
#include <string>
#include <vector>
#include <numeric>

void Solve(std::istream &in, std::ostream &out) {
  int n, target;
  in >> n >> target;
  std::vector<int> orig_nums(n, 0);
  std::vector<int> indexes(n, 0);
  std::iota(indexes.begin(), indexes.end(), 1);
  for (int i = 0; i < n; i++) {
    in >> orig_nums[i];
  }
  std::vector<int> nums(n, 0);
  std::sort(indexes.begin(), indexes.end(),
            [&orig_nums](const int &lhs, const int &rhs) {
              return orig_nums[lhs - 1] < orig_nums[rhs - 1];
            });
  for (int i = 0; i < n; i++) {
    nums[i] = orig_nums[indexes[i] - 1];
  }
  int64_t diff = -1;
  int i = n - 3, j, k;
  while (i >= 0 && diff != 0) {
    j = i + 1, k = n - 1;
    while (j < k && diff != 0) {
      diff = 0;
      diff += nums[i];
      diff += nums[j];
      diff += nums[k];
      diff -= target;
      if (diff > 0) {
        k--;
      } else if (diff < 0) {
        j++;
      }
    }
    if (j >= k) {
      i--;
    }
  }
  if (i >= 0 && diff == 0) {
    out << indexes[i] << ' ' << indexes[j] << ' ' << indexes[k] << '\n';
  } else {
    out << "IMPOSSIBLE\n";
  }
}
