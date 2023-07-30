// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <cctype>

static constexpr char msb1 = 0b10000000;
static constexpr char msb3 = 0b11100000;
static constexpr char msb4 = 0b11110000;
static constexpr char msb5 = 0b11111000;

static constexpr char magic1 = 0b00000000;
static constexpr char magic2 = 0b11000000;
static constexpr char magic3 = 0b11100000;
static constexpr char magic4 = 0b11110000;

void Solve(std::istream &in, std::ostream &out) {
  char c, prev_c = ' ';
  int count = 0;
  int skip = 0;
  while (in.get(c)) {
    if (skip > 0) {
      skip--;
      continue;
    }
    if (!std::isspace(c)) {
      if ((c & msb1) == magic1) {
        skip = 0;
      } else if ((c & msb3) == magic2) {
        skip = 1;
      } else if ((c & msb4) == magic3) {
        skip = 2;
      } else if ((c & msb5) == magic4) {
        skip = 3;
      }
      /*
      1 0xxxxxxx
      2 110yyyyy 10xxxxxx
      3 1110zzzz 10yyyyyy 10xxxxxx
      4 11110uuu 10uuzzzz 10yyyyyy 10xxxxxx
      */
      if (std::isspace(prev_c)) {
        count = 0;
      }
      count++;
    }
    prev_c = c;
  }
  out << count << std::endl;
}

int main() { Solve(std::cin, std::cout); }
