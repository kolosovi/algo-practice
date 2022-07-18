#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max = 0, min = 10001;
        for (auto price : prices) {
            min = std::min(min, price);
            max = std::max(max, price - min);
        }
        return max;
    }
};
