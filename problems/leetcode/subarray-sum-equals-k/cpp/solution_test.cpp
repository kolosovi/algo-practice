#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(TestSubarraySum, 1) {
  Solution solution;
  std::vector<int> nums{1, 1, 1};
  EXPECT_EQ(solution.subarraySum(nums, 2), 2);
}

TEST(TestSubarraySum, 2) {
  Solution solution;
  std::vector<int> nums{1, 2, 3};
  EXPECT_EQ(solution.subarraySum(nums, 3), 2);
}
