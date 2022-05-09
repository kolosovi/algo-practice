#pragma once

#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

static const int32_t kHashMultiplier = 100000;

struct StoneHasher {
  std::size_t operator()(const std::vector<int>& stone) const {
    auto key = kHashMultiplier *
        static_cast<int32_t>(stone[0]) +
        static_cast<int32_t>(stone[1]);
    return int32_t_hash(key);
  }
  std::hash<int32_t> int32_t_hash;
};

struct StoneEqualer {
  bool operator()(const std::vector<int>& lhs, const std::vector<int>& rhs) const {
    return lhs[0] == rhs[0] && lhs[1] == rhs[1];
  }
};

class Solution {
public:
    int removeStones(std::vector<std::vector<int>>& stones) {
        std::unordered_set<std::vector<int>, StoneHasher, StoneEqualer> visited;
        std::unordered_map<int, std::vector<std::vector<int>>> by_x;
        std::unordered_map<int, std::vector<std::vector<int>>> by_y;
        for (const auto &stone : stones) {
            by_x[stone[0]].emplace_back(stone);
            by_y[stone[1]].emplace_back(stone);
        }
        int num_connected_components = 0;
        for (const auto &stone : stones) {
            if (visited.count(stone) > 0) {
                continue;
            }
            visit(stone, visited, by_x, by_y);
            num_connected_components++;
        }
        return stones.size() - num_connected_components;
    }

private:
    void visit(
        const std::vector<int> &stone,
        std::unordered_set<std::vector<int>, StoneHasher, StoneEqualer> &visited,
        std::unordered_map<int, std::vector<std::vector<int>>> &by_x,
        std::unordered_map<int, std::vector<std::vector<int>>> &by_y
    ) {
        visited.insert(stone);
        for (const auto &x_neighbor : by_x[stone[0]]) {
            if (x_neighbor[1] == stone[1] || visited.count(x_neighbor) > 0) {
                continue;
            }
            visit(x_neighbor, visited, by_x, by_y);
        }
        for (const auto &y_neighbor : by_y[stone[1]]) {
            if (y_neighbor[0] == stone[0] || visited.count(y_neighbor) > 0) {
                continue;
            }
            visit(y_neighbor, visited, by_x, by_y);
        }
    }
};
