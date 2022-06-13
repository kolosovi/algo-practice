#pragma once

#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> solutions(amount+1, 0);
        for (int amt = 1; amt <= amount; amt++) {
            int result = -1;
            for (auto coin : coins) {
                if (coin > amt) {
                    continue;
                }
                auto solution = solutions[amt - coin] + 1;
                if (solution == 0) {
                    continue;
                }
                if (result == -1 || solution < result) {
                    result = solution;
                }
            }
            solutions[amt] = result;
        }
        return solutions[amount];
    }
};
