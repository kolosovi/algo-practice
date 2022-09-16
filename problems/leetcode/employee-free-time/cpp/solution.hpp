#pragma once

#include <vector>
#include <algorithm>

class Interval {
 public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

struct IntervalGreater {
  bool operator()(const int &lhs_i, const int &rhs_i) const {
    const auto &lhs = schedule[lhs_i][schedule_pos[lhs_i]];
    const auto &rhs = schedule[rhs_i][schedule_pos[rhs_i]];
    if (lhs.start > rhs.start) {
      return true;
    }
    if (lhs.start == rhs.start) {
      return lhs.end < rhs.end;
    }
    return false;
  }

  const std::vector<std::vector<Interval>> &schedule;
  const std::vector<int> &schedule_pos;
};

class Solution {
 public:
  std::vector<Interval> employeeFreeTime(
      std::vector<std::vector<Interval>> schedule) {
    std::vector<int> schedule_pos(schedule.size(), 0);
    IntervalGreater cmp{schedule, schedule_pos};
    std::vector<int> heads;
    std::make_heap(heads.begin(), heads.end(), cmp);
    for (int i = 0; i < schedule.size(); i++) {
      heads.emplace_back(i);
      std::push_heap(heads.begin(), heads.end(), cmp);
    }
    std::vector<Interval> merged;
    while (heads.size() > 0) {
      auto next_i = heads.front();
      const auto &next = schedule[next_i][schedule_pos[next_i]];
      std::pop_heap(heads.begin(), heads.end(), cmp);
      heads.pop_back();
      if (++schedule_pos[next_i] < schedule[next_i].size()) {
        heads.emplace_back(next_i);
        std::push_heap(heads.begin(), heads.end(), cmp);
      }
      if (merged.size() > 0 && merged.back().end >= next.start) {
        merged.back().end = std::max(merged.back().end, next.end);
      } else {
        merged.push_back(next);
      }
    }
    std::vector<Interval> result;
    result.reserve(merged.size() - 1);
    for (int i = 1; i < merged.size(); i++) {
      result.emplace_back(merged[i - 1].end, merged[i].start);
    }
    return result;
  }
};
