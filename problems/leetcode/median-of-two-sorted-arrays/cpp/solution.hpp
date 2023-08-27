#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size(), m_plus_n = m + n, d = m_plus_n / 2;
    int count_1, count_2;
    int l = 0, r = std::min(d, m);
    while (l <= r) {
      count_1 = l + (r - l) / 2;
      count_2 = d - count_1;
      if (count_2 > n ||
          count_2 > 0 && count_1 < m && nums2[count_2 - 1] > nums1[count_1]) {
        l = count_1 + 1;
      } else {
        r = count_1 - 1;
      }
    }
    count_1 = l, count_2 = d - count_1;
    if (count_1 == 0 && count_2 == 0) {
      return m > 0 ? nums1[0] : nums2[0];
    }
    int max_last, min_next;
    if (count_1 == 0) {
      max_last = nums2[count_2 - 1];
    } else if (count_2 == 0) {
      max_last = nums1[count_1 - 1];
    } else {
      max_last = std::max(nums1[count_1 - 1], nums2[count_2 - 1]);
    }
    if (count_1 == m) {
      min_next = nums2[count_2];
    } else if (count_2 == n) {
      min_next = nums1[count_1];
    } else {
      min_next = std::min(nums1[count_1], nums2[count_2]);
    }
    if (m_plus_n % 2 == 0) {
      return (max_last + min_next) / 2.0;
    }
    return min_next;
  }
};
