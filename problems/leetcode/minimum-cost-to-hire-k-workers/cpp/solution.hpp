#pragma once

#include <algorithm>
#include <vector>
#include <numeric>

struct QualityAsc {
    bool operator()(const int &i, const int &j) const {
        return quality[i] < quality[j];
    }

    const std::vector<int>& quality;
};

class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        if (k == 1) {
            return *std::min_element(wage.begin(), wage.end());
        }
        QualityAsc past_cmp{quality};
        std::vector<int> past;
        int past_quality = 0;
        std::vector<int> workers(wage.size());
        std::iota(workers.begin(), workers.end(), 0);
        std::sort(workers.begin(), workers.end(), [&quality, &wage](int left, int right) {
            auto left_coeff = wage[left] * quality[right], right_coeff = wage[right] * quality[left];
            if (left_coeff == right_coeff) {
                return wage[right] > wage[left];
            }
            return left_coeff < right_coeff;
        });
        bool is_first_group = true;
        double min = 0.0;
        for (auto worker : workers) {
            if (past.size() == k - 1) {
                double cost = static_cast<double>(wage[worker]) + (static_cast<double>(past_quality) * static_cast<double>(wage[worker])) / static_cast<double>(quality[worker]);
                if (is_first_group || cost < min) {
                    min = cost;
                    is_first_group = false;
                }
            }
            past.emplace_back(worker);
            std::push_heap(past.begin(), past.end(), past_cmp);
            past_quality += quality[worker];
            if (past.size() > k - 1) {
                past_quality -= quality[past[0]];
                std::pop_heap(past.begin(), past.end(), past_cmp);
                past.pop_back();
            }
        }
        return min;
    }
};
