#pragma once

#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>

void Solve(std::istream &in, std::ostream &out) {
  int n, num;
  in >> n;
  std::vector<int> candidate_indexes, candidates;
  for (int i = 0; i < n; i++) {
    in >> num;
    auto past_answer_it =
        std::lower_bound(candidates.begin(), candidates.end(), num);
    if (candidates.size() > 0 && past_answer_it != candidates.begin()) {
      out << candidate_indexes[past_answer_it - candidates.begin() - 1];
    } else {
      out << 0;
    }
    if (i != n - 1) {
      out << ' ';
    }
    while (candidates.size() > 0 && candidates.back() >= num) {
      candidates.pop_back();
      candidate_indexes.pop_back();
    }
    candidates.push_back(num);
    candidate_indexes.push_back(i + 1);
  }
  out << '\n';
}
