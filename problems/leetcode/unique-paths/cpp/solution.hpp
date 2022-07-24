#pragma once

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> mem(n+1, 0);
        for (int row = m-1; row >= 0; --row) {
            int prev = 0;
            for (int col = n-1; col >= 0; --col) {
                int cur = prev + mem[col];
                if (cur == 0) {
                    cur = 1;
                }
                mem[col] = cur;
                prev = cur;
            }
        }
        return mem[0];
    }
};
