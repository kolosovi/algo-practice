#include <gtest/gtest.h>

#include "solution.hpp"

TEST(LongestCommonSubsequenceTest, 1) {
    Solution solution;
    EXPECT_EQ(solution.longestCommonSubsequence("zazzzhbczzzdzzef", "ayfybyyyycyydeyh"), 5);
}
