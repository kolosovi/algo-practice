#include <gtest/gtest.h>

#include "solution.hpp"

TEST(LongestPalindromeTest, 1) {
    Solution solution;
    EXPECT_EQ(solution.longestPalindrome("babad"), "bab");
}

TEST(LongestPalindromeTest, 2) {
    Solution solution;
    EXPECT_EQ(solution.longestPalindrome("cbbd"), "bb");
}
