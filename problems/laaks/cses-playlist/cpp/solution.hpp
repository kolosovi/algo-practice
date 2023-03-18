#pragma once

#include <algorithm>
#include <istream>
#include <ostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  // start is included, end is excluded.
  int n, max = 0, start = 0, end = 0, max_song = 0;
  in >> n;
  std::vector<int> songs(n, 0);
  for (int i = 0; i < n; i++) {
    in >> songs[i];
    max_song = std::max(max_song, songs[i]);
  }
  std::vector<bool> unique_songs(max_song + 1, false);
  while (end < n) {
    while (unique_songs[songs[end]]) {
      unique_songs[songs[start++]] = false;
    }
    unique_songs[songs[end++]] = true;
    max = std::max(max, end - start);
  }
  out << max << '\n';
}
