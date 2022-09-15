#pragma once

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
 public:
  int jobScheduling(std::vector<int> &startTime, std::vector<int> &endTime,
                    std::vector<int> &profit) {
    std::vector<int> jobs(startTime.size(), 0);
    std::iota(jobs.begin(), jobs.end(), 0);
    std::sort(jobs.begin(), jobs.end(),
              [&startTime, &endTime](const int &lhs, const int &rhs) -> bool {
                if (startTime[lhs] == startTime[rhs]) {
                  return endTime[lhs] < endTime[rhs];
                }
                return startTime[lhs] < startTime[rhs];
              });
    std::vector<int> mem(jobs.size(), 0);
    return solve(mem, jobs, startTime, endTime, profit, 0);
  }

 private:
  int solve(std::vector<int> &mem, const std::vector<int> &jobs,
            const std::vector<int> &startTime, const std::vector<int> &endTime,
            const std::vector<int> &profit, int i) {
    if (i >= jobs.size()) {
      return 0;
    }
    if (mem[i] > 0) {
      return mem[i];
    }
    int result = solve(mem, jobs, startTime, endTime, profit, i + 1);
    auto first_non_overlapping_it = std::lower_bound(
        jobs.begin(), jobs.end(), endTime[jobs[i]],
        [&startTime](const int &job, const int &target_time) -> bool {
          return startTime[job] < target_time;
        });
    int k = first_non_overlapping_it - jobs.begin();
    int next_profit = solve(mem, jobs, startTime, endTime, profit, k);
    result = std::max(result, profit[jobs[i]] + next_profit);
    mem[i] = result;
    return result;
  }
};
