#pragma once

#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
 public:
  int numBusesToDestination(std::vector<std::vector<int>> &routes, int source,
                            int target) {
    if (source == target) {
      return 0;
    }
    std::vector<std::vector<int>> bus_to_buses(routes.size());
    std::unordered_map<int, std::vector<int>> stop_to_buses;
    std::vector<int> queue;
    std::vector<bool> is_visited(routes.size(), false);
    std::vector<bool> is_final(routes.size(), false);
    for (int bus = 0; bus < routes.size(); ++bus) {
      const auto &stops = routes[bus];
      for (auto stop : stops) {
        stop_to_buses[stop].push_back(bus);
        if (stop == source) {
          queue.push_back(bus);
        }
        if (stop == target) {
          is_final[bus] = true;
        }
      }
    }
    for (int bus = 0; bus < routes.size(); ++bus) {
      const auto &stops = routes[bus];
      std::vector<bool> is_added(routes.size(), false);
      for (auto stop : stops) {
        for (auto other_bus : stop_to_buses[stop]) {
          if (other_bus == bus) {
            continue;
          }
          if (is_added[other_bus] > 0) {
            continue;
          }
          is_added[other_bus] = true;
          bus_to_buses[bus].push_back(other_bus);
        }
      }
    }
    for (int result = 1; queue.size() > 0; ++result) {
      std::vector<int> next_queue;
      for (auto bus : queue) {
        if (is_final[bus]) {
          return result;
        }
        is_visited[bus] = true;
        for (auto next_bus : bus_to_buses[bus]) {
          if (is_visited[next_bus]) {
            continue;
          }
          next_queue.push_back(next_bus);
        }
      }
      std::swap(queue, next_queue);
    }
    return -1;
  }
};
