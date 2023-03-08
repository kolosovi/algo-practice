#pragma once

#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <istream>
#include <ostream>

void Solve(std::istream &in, std::ostream &out) {
  int n, target;
  in >> n >> target;
  std::vector<int> orig_nums(n, 0), nums(n, 0), indexes(n, 0);
  std::iota(indexes.begin(), indexes.end(), 1);
  for (int i = 0; i < n; i++) {
    in >> orig_nums[i];
  }
  std::sort(indexes.begin(), indexes.end(),
            [&orig_nums](const int &lhs, const int &rhs) {
              return orig_nums[lhs - 1] < orig_nums[rhs - 1];
            });
  for (int i = 0; i < n; i++) {
    nums[i] = orig_nums[indexes[i] - 1];
  }
  // i, j, k, l are the four zero-based candidate indexes in `nums`
  int i = n - 4, j, k, l;
  int64_t diff = -1;
  while (i >= 0 && diff != 0) {
    j = n - 3;
    while (j > i && diff != 0) {
      k = j + 1;
      l = n - 1;
      while (k < l && diff != 0) {
        diff = nums[i];
        diff += nums[j];
        diff += nums[k];
        diff += nums[l];
        diff -= target;
        if (diff < 0) {
          k++;
        } else if (diff > 0) {
          l--;
        }
      }
      if (diff != 0) {
        j--;
      }
    }
    if (diff != 0) {
      i--;
    }
  }
  if (diff == 0) {
    out << indexes[i] << ' ' << indexes[j] << ' ' << indexes[k] << ' '
        << indexes[l] << '\n';
  } else {
    out << "IMPOSSIBLE\n";
  }
}
