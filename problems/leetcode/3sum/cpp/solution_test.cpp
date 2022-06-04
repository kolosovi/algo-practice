#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(Problem3SumTest, 1) {
    Solution solution;
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
    EXPECT_EQ(solution.threeSum(nums), expected);
}

TEST(Problem3SumTest, 2) {
    Solution solution;
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> expected{{-1, -1, 2}, {-1, 0, 1}};
    EXPECT_EQ(solution.threeSum(nums), expected);
}
