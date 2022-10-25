// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <istream>
#include <ostream>
#include <vector>
#include <numeric>

void Solve(std::istream &in, std::ostream &out) {
  int n, target;
  in >> n >> target;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    in >> nums[i];
  }
  std::vector<int> ixs(nums.size());
  std::iota(ixs.begin(), ixs.end(), 0);
  std::sort(ixs.begin(), ixs.end(), [&nums](const int &lhs, const int &rhs) {
    return nums[lhs] < nums[rhs];
  });
  int i = 0, j = nums.size() - 1, diff = -1;
  while (i < j && diff != 0) {
    diff = nums[ixs[i]] + nums[ixs[j]] - target;
    if (diff > 0) {
      j--;
    } else if (diff < 0) {
      i++;
    }
  }
  if (diff == 0) {
    out << ixs[i] + 1 << ' ' << ixs[j] + 1 << '\n';
  } else {
    out << "IMPOSSIBLE\n";
  }
}

int main() { Solve(std::cin, std::cout); }
