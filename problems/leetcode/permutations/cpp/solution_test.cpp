#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(PermutationsTest, 1) {
    Solution solution;
    std::vector<int> nums{1};
    std::vector<std::vector<int>> expected{{1}};
    EXPECT_EQ(solution.permute(nums), expected);
}

TEST(PermutationsTest, 2) {
    Solution solution;
    std::vector<int> nums{1, 2};
    std::vector<std::vector<int>> expected{{1, 2}, {2, 1}};
    EXPECT_EQ(solution.permute(nums), expected);
}

TEST(PermutationsTest, 3) {
    Solution solution;
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> expected{
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1},
    };
    EXPECT_EQ(solution.permute(nums), expected);
}

TEST(PermutationsTest, 4) {
    Solution solution;
    std::vector<int> nums{1, 2, 3, 4};
    std::vector<std::vector<int>> expected{
        {1, 2, 3, 4},
        {1, 2, 4, 3},
        {1, 3, 2, 4},
        {1, 3, 4, 2},
        {1, 4, 2, 3},
        {1, 4, 3, 2},
        {2, 1, 3, 4},
        {2, 1, 4, 3},
        {2, 3, 1, 4},
        {2, 3, 4, 1},
        {2, 4, 1, 3},
        {2, 4, 3, 1},
        {3, 1, 2, 4},
        {3, 1, 4, 2},
        {3, 2, 1, 4},
        {3, 2, 4, 1},
        {3, 4, 1, 2},
        {3, 4, 2, 1},
        {4, 1, 2, 3},
        {4, 1, 3, 2},
        {4, 2, 1, 3},
        {4, 2, 3, 1},
        {4, 3, 1, 2},
        {4, 3, 2, 1},
    };
    EXPECT_EQ(solution.permute(nums), expected);
}

TEST(PermutationsTest, 5) {
    Solution solution;
    std::vector<int> nums{1, 2, 3, 4, 5};
    std::vector<std::vector<int>> expected{
		{1, 2, 3, 4, 5},
		{1, 2, 3, 5, 4},
		{1, 2, 4, 3, 5},
		{1, 2, 4, 5, 3},
		{1, 2, 5, 3, 4},
		{1, 2, 5, 4, 3},
		{1, 3, 2, 4, 5},
		{1, 3, 2, 5, 4},
		{1, 3, 4, 2, 5},
		{1, 3, 4, 5, 2},
		{1, 3, 5, 2, 4},
		{1, 3, 5, 4, 2},
		{1, 4, 2, 3, 5},
		{1, 4, 2, 5, 3},
		{1, 4, 3, 2, 5},
		{1, 4, 3, 5, 2},
		{1, 4, 5, 2, 3},
		{1, 4, 5, 3, 2},
		{1, 5, 2, 3, 4},
		{1, 5, 2, 4, 3},
		{1, 5, 3, 2, 4},
		{1, 5, 3, 4, 2},
		{1, 5, 4, 2, 3},
		{1, 5, 4, 3, 2},
		{2, 1, 3, 4, 5},
		{2, 1, 3, 5, 4},
		{2, 1, 4, 3, 5},
		{2, 1, 4, 5, 3},
		{2, 1, 5, 3, 4},
		{2, 1, 5, 4, 3},
		{2, 3, 1, 4, 5},
		{2, 3, 1, 5, 4},
		{2, 3, 4, 1, 5},
		{2, 3, 4, 5, 1},
		{2, 3, 5, 1, 4},
		{2, 3, 5, 4, 1},
		{2, 4, 1, 3, 5},
		{2, 4, 1, 5, 3},
		{2, 4, 3, 1, 5},
		{2, 4, 3, 5, 1},
		{2, 4, 5, 1, 3},
		{2, 4, 5, 3, 1},
		{2, 5, 1, 3, 4},
		{2, 5, 1, 4, 3},
		{2, 5, 3, 1, 4},
		{2, 5, 3, 4, 1},
		{2, 5, 4, 1, 3},
		{2, 5, 4, 3, 1},
		{3, 1, 2, 4, 5},
		{3, 1, 2, 5, 4},
        {3, 1, 4, 2, 5},
        {3, 1, 4, 5, 2},
        {3, 1, 5, 2, 4},
        {3, 1, 5, 4, 2},
        {3, 2, 1, 4, 5},
        {3, 2, 1, 5, 4},
        {3, 2, 4, 1, 5},
        {3, 2, 4, 5, 1},
        {3, 2, 5, 1, 4},
        {3, 2, 5, 4, 1},
        {3, 4, 1, 2, 5},
        {3, 4, 1, 5, 2},
        {3, 4, 2, 1, 5},
        {3, 4, 2, 5, 1},
        {3, 4, 5, 1, 2},
        {3, 4, 5, 2, 1},
        {3, 5, 1, 2, 4},
        {3, 5, 1, 4, 2},
        {3, 5, 2, 1, 4},
        {3, 5, 2, 4, 1},
        {3, 5, 4, 1, 2},
        {3, 5, 4, 2, 1},
        {4, 1, 2, 3, 5},
        {4, 1, 2, 5, 3},
        {4, 1, 3, 2, 5},
        {4, 1, 3, 5, 2},
        {4, 1, 5, 2, 3},
        {4, 1, 5, 3, 2},
        {4, 2, 1, 3, 5},
        {4, 2, 1, 5, 3},
        {4, 2, 3, 1, 5},
        {4, 2, 3, 5, 1},
        {4, 2, 5, 1, 3},
        {4, 2, 5, 3, 1},
        {4, 3, 1, 2, 5},
        {4, 3, 1, 5, 2},
        {4, 3, 2, 1, 5},
        {4, 3, 2, 5, 1},
        {4, 3, 5, 1, 2},
        {4, 3, 5, 2, 1},
        {4, 5, 1, 2, 3},
        {4, 5, 1, 3, 2},
        {4, 5, 2, 1, 3},
        {4, 5, 2, 3, 1},
        {4, 5, 3, 1, 2},
        {4, 5, 3, 2, 1},
        {5, 1, 2, 3, 4},
        {5, 1, 2, 4, 3},
        {5, 1, 3, 2, 4},
        {5, 1, 3, 4, 2},
        {5, 1, 4, 2, 3},
        {5, 1, 4, 3, 2},
        {5, 2, 1, 3, 4},
        {5, 2, 1, 4, 3},
        {5, 2, 3, 1, 4},
        {5, 2, 3, 4, 1},
        {5, 2, 4, 1, 3},
        {5, 2, 4, 3, 1},
        {5, 3, 1, 2, 4},
        {5, 3, 1, 4, 2},
        {5, 3, 2, 1, 4},
        {5, 3, 2, 4, 1},
        {5, 3, 4, 1, 2},
        {5, 3, 4, 2, 1},
        {5, 4, 1, 2, 3},
        {5, 4, 1, 3, 2},
        {5, 4, 2, 1, 3},
        {5, 4, 2, 3, 1},
        {5, 4, 3, 1, 2},
        {5, 4, 3, 2, 1},
    };
    EXPECT_EQ(solution.permute(nums), expected);
}
