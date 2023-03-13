// This code was generated, do not edit.

#include <iostream>

#include <cstdint>
#include <istream>
#include <ostream>
#include <vector>
#include <unordered_map>

struct Acc {
  explicit Acc(int target_count)
      : target_count(target_count), actual_count(0) {}

  void Add(int num) {
    if (freqs[num]++ == 0) {
      actual_count++;
    }
  }

  void Remove(int num) {
    if (--freqs[num] == 0) {
      actual_count--;
    }
  }

  bool IsGood() const { return actual_count <= target_count; }

  std::unordered_map<int, int> freqs;
  int target_count;
  int actual_count;
};

int64_t Count(int64_t first_i, int64_t last_i) {
  auto n = last_i - first_i + 1;
  return (n * (n + 1)) / 2;
}

void Solve(std::istream &in, std::ostream &out) {
  int64_t result = 0;
  int n, k;
  in >> n >> k;
  std::vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) {
    in >> nums[i];
  }
  int l = 0, r = 0, cur_good_r = 0, prev_good_r = -1;
  bool is_good = true;
  Acc acc(k);
  acc.Add(nums[0]);
  while (l <= r && l < n) {
    if (!acc.IsGood()) {
      if (is_good) {
        is_good = false;
        result += Count(l, cur_good_r);
      }
      acc.Remove(nums[l++]);
      continue;
    }
    if (!is_good) {
      is_good = true;
      prev_good_r = cur_good_r;
      result -= Count(l, prev_good_r);
    }
    cur_good_r = r;
    if (r < n - 1) {
      acc.Add(nums[++r]);
    } else {
      break;
    }
  }
  result += Count(l, cur_good_r);
  out << result << '\n';
}

int main() { Solve(std::cin, std::cout); }
