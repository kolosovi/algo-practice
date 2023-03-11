// This code was generated, do not edit.

#include <iostream>

#include <cstdint>
#include <istream>
#include <ostream>
#include <vector>
#include <unordered_map>

void Solve(std::istream &in, std::ostream &out) {
  int n, target;
  in >> n >> target;
  int64_t sum = 0, result = 0, number;
  std::unordered_map<int64_t, int64_t> sum_counts{{0, 1}};
  for (int i = 0; i < n; i++) {
    in >> number;
    sum += number;
    int64_t wanted = sum - target;
    auto wanted_count_it = sum_counts.find(wanted);
    if (wanted_count_it != sum_counts.end()) {
      result += wanted_count_it->second;
    }
    sum_counts[sum]++;
  }
  out << result << '\n';
}

int main() { Solve(std::cin, std::cout); }
