// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <string>

void Solve(std::istream &in, std::ostream &out) {
  std::string input;
  in >> input;
  int k = 0;
  int j = input.size() - 1, l = input.size() - k - 1;
  out << "input size = [" << input.size() << "], input.size() - 1 = ["
      << input.size() - 1 << "], j = [" << j << "], l = [" << l << "]"
      << std::endl;
  for (int i = input.size() - 1; i >= 0; i--) {
    std::cerr << "[" << input[i] << "]" << std::endl;
    out << "[" << input[i] << "]" << std::endl;
  }
  std::cerr << "after first loop" << std::endl;
  for (int i = 0; i < input.size() - i - 1; i++) {
    std::cerr << "i = [" << i << "], input.size() - i - 1 = ["
              << input.size() - i - 1 << "]" << std::endl;
    std::swap(input[i], input[input.size() - i - 1]);
  }
}

int main() { Solve(std::cin, std::cout); }
