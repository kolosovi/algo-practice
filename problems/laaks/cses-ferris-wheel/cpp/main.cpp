// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <istream>
#include <ostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  int n, max;
  in >> n >> max;
  std::vector<int> weights(n);
  while (n-- > 0) {
    in >> weights[n];
  }
  std::sort(weights.begin(), weights.end());
  int count = 0, i = 0;
  while (i < weights.size()) {
    while (i < weights.size() - 1 && weights[i] + weights.back() > max) {
      count++;
      weights.pop_back();
    }
    i++;
    count++;
    if (i < weights.size()) {
      weights.pop_back();
    }
  }
  out << count << '\n';
}

int main() { Solve(std::cin, std::cout); }
