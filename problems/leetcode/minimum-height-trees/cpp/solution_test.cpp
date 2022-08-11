#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(FindMinHeightTreesTest, 1) {
    Solution solution;
    std::vector<std::vector<int>> edges{{1,0},{1,2},{1,3}};
    std::vector<int> expected{1};
    EXPECT_EQ(solution.findMinHeightTrees(4, edges), expected);
}
