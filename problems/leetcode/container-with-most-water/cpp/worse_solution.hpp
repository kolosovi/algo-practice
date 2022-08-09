#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        std::vector<int> leftward_max_i;
        for (int i = height.size()-1; i >= 0; i--) {
            if (leftward_max_i.size() == 0 || height[i] > height[leftward_max_i.back()]) {
                leftward_max_i.push_back(i);
            }
        }
        int max_area = 0, start = 0, rightward_max = -1;
        for (int l = 0; l < height.size(); l++) {
            if (height[l] <= rightward_max) {
                continue;
            }
            rightward_max = height[l];
            int i = start;
            for (; i < leftward_max_i.size(); i++) {
                if (leftward_max_i[i] <= l) {
                    break;
                }
                max_area = std::max(max_area, std::min(height[l], height[leftward_max_i[i]]) * (leftward_max_i[i] - l));
                if (height[leftward_max_i[i]] >= height[l]) {
                    break;
                }
            }
            start = i;
        }
        return max_area;
    }
};
