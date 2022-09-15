#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
 public:
  int minAreaRect(std::vector<std::vector<int>> &points) {
    std::unordered_map<int, std::set<int>> x_to_ys;
    std::unordered_map<int, std::set<int>> y_to_xs;
    for (const auto &p : points) {
      x_to_ys[p[0]].emplace(p[1]);
      y_to_xs[p[1]].emplace(p[0]);
    }
    const int kImpossibleResult = 1600000001;
    int result = kImpossibleResult;
    for (const auto &[x, ys] : x_to_ys) {
      for (auto y_it = ys.begin(); y_it != ys.end(); y_it++) {
        const auto &xs = y_to_xs[*y_it];
        auto right_x_it = xs.upper_bound(x);
        for (; right_x_it != xs.end(); ++right_x_it) {
          auto &right_ys = x_to_ys[*right_x_it];
          auto right_y_it = right_ys.upper_bound(*y_it);
          auto left_y_it = std::next(y_it);
          while (left_y_it != ys.end() && right_y_it != right_ys.end() &&
                 *left_y_it != *right_y_it) {
            if (*left_y_it < *right_y_it) {
              left_y_it++;
            } else {
              right_y_it++;
            }
          }
          if (left_y_it != ys.end() && right_y_it != right_ys.end() &&
              *left_y_it == *right_y_it) {
            result =
                std::min(result, (*right_x_it - x) * (*right_y_it - *y_it));
          }
        }
      }
    }
    return result == kImpossibleResult ? 0 : result;
  }
};
