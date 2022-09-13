#pragma once

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        std::vector<int> jobs(startTime.size(), 0);
        std::iota(jobs.begin(), jobs.end(), 0);
        std::sort(
            jobs.begin(),
            jobs.end(),
            [&startTime, &endTime](const int &lhs, const int &rhs) -> bool {
                if (startTime[lhs] == startTime[rhs]) {
                    return endTime[lhs] < endTime[rhs];
                }
                return startTime[lhs] < startTime[rhs];
            }
        );
        std::vector<int> mem(jobs.size(), 0);
        int result = solve(mem, jobs, startTime, endTime, profit, 0);
        for (int i = 1; i < jobs.size(); i++) {
            if (startTime[jobs[i]] >= endTime[jobs[0]]) {
                break;
            }
            result = std::max(result, solve(mem, jobs, startTime, endTime, profit, i));
        }
        return result;
    }

private:
    int solve(std::vector<int> &mem, const std::vector<int> &jobs, const std::vector<int> &startTime, const std::vector<int> &endTime, const std::vector<int> &profit, int i) {
        if (mem[i] > 0) {
            return mem[i];
        }
        int additional_profit = 0;
        auto first_non_overlapping_it = std::lower_bound(
            jobs.begin(),
            jobs.end(),
            endTime[jobs[i]],
            [&startTime](const int &job, const int &target_time) -> bool {
                return startTime[job] < target_time;
            }
        );
        if (first_non_overlapping_it == jobs.end()) {
            mem[i] = profit[jobs[i]];
            return mem[i];
        }
        int k = first_non_overlapping_it - jobs.begin();
        additional_profit = std::max(additional_profit, solve(mem, jobs, startTime, endTime, profit, k));
        for (int next_k = k + 1; next_k < jobs.size(); next_k++) {
            if (startTime[jobs[next_k]] >= endTime[jobs[k]]) {
                break;
            }
            additional_profit = std::max(additional_profit, solve(mem, jobs, startTime, endTime, profit, next_k));
        }
        mem[i] = profit[jobs[i]] + additional_profit;
        return mem[i];
    }
};
