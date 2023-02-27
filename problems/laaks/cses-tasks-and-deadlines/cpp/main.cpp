// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

void Solve(std::istream &in, std::ostream &out) {
  int n;
  int64_t elapsed = 0, reward = 0;
  in >> n;
  std::vector<int> durations(n, 0);
  std::vector<int> deadlines(n, 0);
  std::vector<int> tasks(n, 0);
  std::iota(tasks.begin(), tasks.end(), 0);
  for (int i = 0; i < n; i++) {
    in >> durations[i];
    in >> deadlines[i];
  }
  std::sort(tasks.begin(), tasks.end(),
            [&durations](const int &lhs, const int &rhs) {
              return durations[lhs] < durations[rhs];
            });
  for (auto task : tasks) {
    elapsed += static_cast<int64_t>(durations[task]);
    reward += static_cast<int64_t>(deadlines[task]) - elapsed;
  }
  out << reward << '\n';
}

int main() { Solve(std::cin, std::cout); }
