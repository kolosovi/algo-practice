// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <istream>
#include <ostream>
#include <vector>
#include <utility>

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::pair<int, int>> movies;
  movies.reserve(n);
  while (n-- > 0) {
    movies.emplace_back();
    in >> movies.back().first;
    in >> movies.back().second;
  }
  std::sort(movies.begin(), movies.end(),
            [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
              return lhs.second < rhs.second;
            });
  int i = 0, count = 0;
  while (i < movies.size()) {
    int j = i + 1;
    for (; j < movies.size() && movies[j].first < movies[i].second; j++) {
    }
    count++;
    i = j;
  }
  out << count << '\n';
}

int main() { Solve(std::cin, std::cout); }
