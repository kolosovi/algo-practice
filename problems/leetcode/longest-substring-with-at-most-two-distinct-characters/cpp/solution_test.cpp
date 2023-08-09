#include <gtest/gtest.h>

#include "solution.hpp"

#include <string>

TEST(LongestSubstringWithAtMostTwoDistinctCharacters, 1) {
  Solution solution;
  EXPECT_EQ(solution.lengthOfLongestSubstringTwoDistinct("ccaabbb"), 5);
}
