#pragma once

#include <istream>
#include <ostream>
#include <vector>

int Count(std::vector<int> &indexes, int n, int num) {
  if (num == 1 || num <= n && indexes[num] < indexes[num - 1]) {
    return 1;
  }
  return 0;
}

void Solve(std::istream &in, std::ostream &out) {
  int n, ops_count, pos_a, pos_b, count = 0;
  in >> n >> ops_count;
  std::vector<int> nums(n + 1, 0);
  std::vector<int> indexes(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    in >> nums[i];
    indexes[nums[i]] = i;
  }
  for (int num = 1; num <= n; num++) {
    count += Count(indexes, n, num);
  }
  while (ops_count-- > 0) {
    in >> pos_a >> pos_b;
    int old_count = 0, new_count = 0;
    auto &a = nums[pos_a], &b = nums[pos_b];
    old_count += Count(indexes, n, a) + Count(indexes, n, a + 1);
    if (b != a + 1) {
      old_count += Count(indexes, n, b);
    }
    if (b + 1 != a) {
      old_count += Count(indexes, n, b + 1);
    }
    std::swap(indexes[a], indexes[b]);
    std::swap(a, b);
    new_count += Count(indexes, n, a) + Count(indexes, n, a + 1);
    if (b != a + 1) {
      new_count += Count(indexes, n, b);
    }
    if (b + 1 != a) {
      new_count += Count(indexes, n, b + 1);
    }
    count += (new_count - old_count);
    out << count << '\n';
  }
}
