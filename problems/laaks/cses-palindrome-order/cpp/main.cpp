// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <string>
#include <cstring>

static constexpr int kAlphabetSize = 26;
static int freqs[kAlphabetSize];
static constexpr char kA = 'A';
static constexpr char kZ = 'Z';

void Solve(std::istream &in, std::ostream &out) {
  std::string word;
  in >> word;
  std::memset(freqs, 0, sizeof(freqs));
  for (auto letter : word) {
    freqs[letter - kA]++;
  }
  int offset = 0;
  char odd_letter = 0;
  for (char letter = kA; letter <= kZ; ++letter) {
    auto freq = freqs[letter - kA];
    int count = freq / 2, rem = freq % 2;
    if (rem == 1) {
      if (odd_letter) {
        out << "NO SOLUTION\n";
        return;
      }
      odd_letter = letter;
    }
    while (count-- > 0) {
      word[offset] = letter;
      word[word.size() - offset - 1] = letter;
      offset++;
    }
  }
  if (odd_letter) {
    word[offset] = odd_letter;
  }
  out << word << '\n';
}

int main() { Solve(std::cin, std::cout); }
