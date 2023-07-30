// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <istream>
#include <ostream>
#include <string>

void Solve(std::istream &in, std::ostream &out) {
  int num;
  in >> num;
  while (num != 0 && num % 10 == 0) {
    num /= 10;
  }
  auto formatted = std::to_string(num);
  int low = 0, high = formatted.size() - 1;
  if (low < high && formatted[low] == '-') {
    low++;
  }
  while (low < high) {
    std::swap(formatted[low], formatted[high]);
    low++;
    high--;
  }
  out << formatted << std::endl;
}

int main() { Solve(std::cin, std::cout); }
