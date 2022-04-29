#include <algorithm>
#include <vector>
#include <unordered_map>
#include <tuple>

class Solution {
public:
    int minAreaRect(std::vector<std::vector<int>>& points) {
        std::unordered_map<int, std::vector<std::vector<int>>> y_to_points;
        for (const auto &point : points) {
            y_to_points[point[1]].push_back(point);
        }
        std::vector<std::tuple<int, int, int>> edges;
        for (const auto &[y, points] : y_to_points) {
            for (int i = 0; i < points.size(); i++) {
                for (int j = i+1; j < points.size(); j++) {
                    auto left_x = std::min(points[i][0], points[j][0]);
                    auto right_x = std::max(points[i][0], points[j][0]);
                    edges.emplace_back(right_x - left_x, left_x, y);
                }
            }
        }
        std::sort(edges.begin(), edges.end());
        int result = 0;
        for (int i = 1; i < edges.size(); i++) {
            auto &[length, x, y] = edges[i];
            auto &[prev_length, prev_x, prev_y] = edges[i-1];
            if (length != prev_length || x != prev_x) {
                continue;
            }
            auto area = length * (y - prev_y);
            if (result == 0 || area < result) {
                result = area;
            }
        }
        return result;
    }
};
