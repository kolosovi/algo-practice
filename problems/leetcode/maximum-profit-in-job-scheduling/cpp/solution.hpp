#pragma once

#include <vector>
#include <numeric>
#include <algorithm>

struct Compare {
    bool operator()(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) const {
        return lhs.first > rhs.first;
    }
};

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
        Compare cmp;
        std::vector<std::pair<int, int>> queue;
        std::make_heap(queue.begin(), queue.end(), cmp);
        int max_profit = 0;
        for (auto job : jobs) {
            while (queue.size() > 0 && queue.front().first <= startTime[job]) {
                max_profit = std::max(max_profit, queue.front().second);
                std::pop_heap(queue.begin(), queue.end(), cmp);
                queue.pop_back();
            }
            queue.emplace_back(endTime[job], profit[job] + max_profit);
            std::push_heap(queue.begin(), queue.end(), cmp);
        }
        for (const auto &[_, a_profit] : queue) {
            max_profit = std::max(max_profit, a_profit);
        }
        return max_profit;
    }
};
