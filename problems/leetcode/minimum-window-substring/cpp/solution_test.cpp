#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(MinimumWindowSubstring, 1) {
  Solution solution;
  EXPECT_EQ(solution.minWindow("ADOBECODEBANC", "ABC"), "BANC");
}

TEST(MinimumWindowSubstring, 2) {
  Solution solution;
  EXPECT_EQ(solution.minWindow("a", "a"), "a");
}

TEST(MinimumWindowSubstring, 3) {
  Solution solution;
  EXPECT_EQ(solution.minWindow("a", "aa"), "");
}
