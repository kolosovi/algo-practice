// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <algorithm>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  int num_applicants, num_apartments, max_diff;
  in >> num_applicants >> num_apartments >> max_diff;
  std::vector<int> desired(num_applicants);
  std::vector<int> sizes(num_apartments);
  for (int i = 0; i < num_applicants; i++) {
    in >> desired[i];
  }
  for (int i = 0; i < num_apartments; i++) {
    in >> sizes[i];
  }
  std::sort(desired.begin(), desired.end(), std::greater<int>{});
  std::sort(sizes.begin(), sizes.end(), std::greater<int>{});
  int count = 0, i = 0;
  for (auto size : sizes) {
    for (; i < desired.size() && desired[i] - max_diff > size; ++i) {
    }
    if (i == desired.size() || desired[i] + max_diff < size) {
      continue;
    }
    count++;
    i++;
  }
  out << count << '\n';
}

int main() { Solve(std::cin, std::cout); }
