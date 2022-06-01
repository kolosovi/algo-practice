#pragma once

#include <vector>
#include <limits>
#include <utility>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        std::vector<int> row(n, std::numeric_limits<int>::max());
        std::vector<std::vector<int>> result(m, row);
        std::vector<std::pair<int, int>> queue;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    queue.emplace_back(i, j);
                }
            }
        }
        for (int level = 0; queue.size() > 0; level++) {
            std::vector<std::pair<int, int>> next_queue;
            for (auto [i, j] : queue) {
                if (result[i][j] < level) {
                    continue;
                }
                result[i][j] = level;
                if (i < m-1) {
                    next_queue.emplace_back(i + 1, j);
                }
                if (i > 0) {
                    next_queue.emplace_back(i - 1, j);
                }
                if (j < n-1) {
                    next_queue.emplace_back(i, j+1);
                }
                if (j > 0) {
                    next_queue.emplace_back(i, j-1);
                }
            }
            std::swap(queue, next_queue);
            next_queue.clear();
        }
        return result;
    }
};
