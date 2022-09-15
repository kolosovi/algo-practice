#pragma once

#include <map>

class Solution {
 public:
  std::pair<std::pair<int, int>, std::pair<int, int>> Add(int x, int y) {
    xs_[x]++;
    ys_[y]++;
    return calcBoundingBox();
  }

  std::pair<std::pair<int, int>, std::pair<int, int>> Remove(int x, int y) {
    auto it = xs_.find(x);
    if (--(xs_[x]) == 0) {
      xs_.erase(x);
    }
    if (--(ys_[y]) == 0) {
      ys_.erase(y);
    }
    return calcBoundingBox();
  }

 private:
  std::map<int, int> xs_;
  std::map<int, int> ys_;

  std::pair<std::pair<int, int>, std::pair<int, int>> calcBoundingBox() const {
    if (xs_.size() > 0 && ys_.size() > 0) {
      auto min_x_it = xs_.begin();
      auto max_x_it = xs_.rbegin();
      auto min_y_it = ys_.begin();
      auto max_y_it = ys_.rbegin();
      return {{min_x_it->first, max_y_it->first},
              {max_x_it->first, min_y_it->first}};
    }
    return {{0, 0}, {0, 0}};
  }
};
