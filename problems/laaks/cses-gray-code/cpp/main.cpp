// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <vector>
#include <string>

void solve(std::vector<std::string> &solution, int n) {
  if (n == 1) {
    solution.push_back("0");
    solution.push_back("1");
    return;
  }
  solve(solution, n - 1);
  int size = solution.size();
  for (int i = size - 1; i >= 0; i--) {
    solution.push_back(solution[i]);
    solution.back().push_back('1');
    solution[i].push_back('0');
  }
}

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::string> solution;
  solve(solution, n);
  for (const auto &code : solution) {
    out << code << '\n';
  }
}

int main() { Solve(std::cin, std::cout); }
