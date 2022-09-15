#pragma once

#include <algorithm>
#include <vector>

class Less {
 public:
  bool operator()(const std::vector<int> &lhs, const std::vector<int> &rhs) {
    return calcDistance(lhs) < calcDistance(rhs);
  }

 private:
  static inline int calcDistance(const std::vector<int> &point) {
    return point[0] * point[0] + point[1] * point[1];
  }
};

class Solution {
 public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                         int k) {
    Less less;
    std::vector<std::vector<int>> heap;
    for (const auto &point : points) {
      heap.push_back(point);
      std::push_heap(heap.begin(), heap.end(), less);
      if (heap.size() > k) {
        std::pop_heap(heap.begin(), heap.end(), less);
        heap.pop_back();
      }
    }
    return heap;
  }
};
