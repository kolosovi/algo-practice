// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>
#include <string>
#include <vector>
#include <cstring>

static constexpr char kA = 'a', kZ = 'z';

void solve(std::vector<std::string> &result, std::vector<char> &freq,
           std::string &word, std::size_t i) {
  if (i == word.size()) {
    result.push_back(word);
    return;
  }
  for (char letter = kA; letter <= kZ; letter++) {
    if (!freq[letter - kA]) {
      continue;
    }
    word[i] = letter;
    freq[letter - kA]--;
    solve(result, freq, word, i + 1);
    freq[letter - kA]++;
  }
}

void Solve(std::istream &in, std::ostream &out) {
  std::string word;
  in >> word;
  std::vector<char> freq(kZ - kA + 1, 0);
  for (auto letter : word) {
    freq[letter - kA]++;
  }
  int w = 0;
  for (char letter = kA; letter <= kZ; letter++) {
    for (int i = 0; i < freq[letter - kA]; i++) {
      word[w++] = letter;
    }
  }
  std::vector<std::string> result;
  solve(result, freq, word, 0);
  out << result.size() << '\n';
  for (auto permutation : result) {
    out << permutation << '\n';
  }
}

int main() { Solve(std::cin, std::cout); }
