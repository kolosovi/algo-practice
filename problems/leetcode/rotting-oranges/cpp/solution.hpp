#pragma once

#include <vector>
#include <utility>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::vector<std::pair<int, int>> queue;
        int fresh_count = 0;
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid[0].size(); ++y) {
                if (grid[x][y] == 2) {
                    queue.emplace_back(x, y);
                } else if (grid[x][y] == 1) {
                    fresh_count++;
                }
            }
        }
        std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int iter = 0;
        for (; queue.size() > 0 && fresh_count > 0; iter++) {
            std::vector<std::pair<int, int>> next_queue;
            for (auto [x, y] : queue) {
                for (auto [dx, dy] : directions) {
                    if (x+dx < 0 || x+dx >= grid.size() || y+dy < 0 || y+dy >= grid[0].size()) {
                        continue;
                    }
                    if (grid[x+dx][y+dy] != 1) {
                        continue;
                    }
                    grid[x+dx][y+dy] = 2;
                    next_queue.emplace_back(x+dx, y+dy);
                    fresh_count--;
                }
            }
            std::swap(queue, next_queue);
            next_queue.clear();
        }
        return fresh_count == 0 ? iter : -1;
    }
};
