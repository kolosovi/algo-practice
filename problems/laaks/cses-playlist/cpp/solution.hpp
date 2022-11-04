#pragma once

#include <algorithm>
#include <istream>
#include <ostream>
#include <unordered_set>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  // start is included, end is excluded.
  int n, max = 0, start = 0, end = 0;
  in >> n;
  std::vector<int> songs(n, 0);
  std::unordered_set<int> unique_songs;
  for (int i = 0; i < n; i++) {
    in >> songs[i];
  }
  while (end <= n) {
    max = std::max(max, end - start);
    if (end == n) {
      break;
    }
    if (unique_songs.count(songs[end]) > 0) {
      unique_songs.erase(songs[start++]);
      continue;
    }
    unique_songs.insert(songs[end++]);
  }
  out << max << '\n';
}
