#pragma once

#include <vector>

class Solution {
 public:
  int peakIndexInMountainArray(std::vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (m != arr.size() - 1 && arr[m] < arr[m + 1]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return r;
  }
};
