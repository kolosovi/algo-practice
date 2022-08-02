#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(SubsetsTest, 1) {
    Solution solution;
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> expected{{}, {3}, {2}, {3, 2}, {1}, {3, 1}, {2, 1}, {3, 2, 1}};
    EXPECT_EQ(solution.subsets(nums), expected);
}
