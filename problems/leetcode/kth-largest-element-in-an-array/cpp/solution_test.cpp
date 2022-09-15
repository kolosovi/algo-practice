#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(KthLargestElementInAnArrayTest, 1) {
  Solution solution;
  std::vector<int> nums{3, 2, 1, 5, 6, 4};
  EXPECT_EQ(solution.findKthLargest(nums, 2), 5);
}
