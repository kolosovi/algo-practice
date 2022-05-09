#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(MostStonesRemovedWithSameRowOrColumnTest, 1) {
    Solution solution;
    std::vector<std::vector<int>> stones{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    EXPECT_EQ(solution.removeStones(stones), 5);
}

TEST(MostStonesRemovedWithSameRowOrColumnTest, 2) {
    Solution solution;
    std::vector<std::vector<int>> stones{{0,0},{0,1},{1,0},{1,1},{2,1},{2,2},{3,2},{3,3},{3,4},{4,3},{4,4}};
    EXPECT_EQ(solution.removeStones(stones), 10);
}

TEST(MostStonesRemovedWithSameRowOrColumnTest, 3) {
    Solution solution;
    std::vector<std::vector<int>> stones{{5,9}, {9,0}, {0,0}, {7,0}, {4,3}, {8,5}, {5,8}, {1,1}, {0,6}, {7,5}, {1,6}, {1,9}, {9,4}, {2,8}, {1,3}, {4,2}, {2,5}, {4,1}, {0,2}, {6,5}};
    EXPECT_EQ(solution.removeStones(stones), 19);
}
