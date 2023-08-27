#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(FindMedianSortedArrays, 1) {
  Solution solution;
  std::vector<int> nums1{1, 3};
  std::vector<int> nums2{2};
  EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 2.0);
}

TEST(FindMedianSortedArrays, 2) {
  Solution solution;
  std::vector<int> nums1{1, 2};
  std::vector<int> nums2{3, 4};
  EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 2.5);
}

TEST(FindMedianSortedArrays, 3) {
  Solution solution;
  std::vector<int> nums1{1};
  std::vector<int> nums2{2, 3, 4};
  EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 2.5);
}

TEST(FindMedianSortedArrays, 4) {
  Solution solution;
  std::vector<int> nums1{1};
  std::vector<int> nums2{};
  EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 1.0);
}

TEST(FindMedianSortedArrays, 5) {
  Solution solution;
  std::vector<int> nums1{};
  std::vector<int> nums2{1};
  EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 1.0);
}
