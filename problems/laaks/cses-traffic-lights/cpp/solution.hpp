#pragma once

#include <istream>
#include <ostream>
#include <map>
#include <map>

void Solve(std::istream &in, std::ostream &out) {
  int x, n, pos;
  in >> x >> n;
  // start position -> length of run
  std::map<int, int, std::greater<int>> runs({{0, x}});
  // length of run -> count of such runs
  std::map<int, int> len_counts({{x, 1}});
  while (n-- > 0) {
    in >> pos;
    auto run_it = runs.lower_bound(pos);

    auto [new_run_it, inserted] =
        runs.insert({pos, run_it->first + run_it->second - pos});
    len_counts[new_run_it->second]++;

    auto old_len_it = len_counts.find(run_it->second);
    if (--old_len_it->second == 0) {
      len_counts.erase(old_len_it);
    }
    run_it->second = pos - run_it->first;
    len_counts[run_it->second]++;

    out << len_counts.rbegin()->first;
    if (n > 0) {
      out << ' ';
    }
  }
  out << '\n';
}
