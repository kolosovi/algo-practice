#include <gtest/gtest.h>

#include "solution.hpp"

#include <string>

TEST(TestWildcardIsMatch, 1) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("aa", "a"));
}

TEST(TestWildcardIsMatch, 2) {
  Solution solution;
  EXPECT_TRUE(solution.isMatch("aa", "*"));
}

TEST(TestWildcardIsMatch, 3) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("cb", "?a"));
}

TEST(TestWildcardIsMatch, 4) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("cb", "?a"));
}

TEST(TestWildcardIsMatch, 5) {
  Solution solution;
  EXPECT_TRUE(solution.isMatch("abc", "abc"));
}

TEST(TestWildcardIsMatch, 6) {
  Solution solution;
  EXPECT_TRUE(solution.isMatch("abc", "abc*"));
}

TEST(TestWildcardIsMatch, 7) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("abc", "ab"));
}

TEST(TestWildcardIsMatch, 8) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("abcdefgh", "ab*c*k"));
}

TEST(TestWildcardIsMatch, 9) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("abcdefgh", ""));
}

TEST(TestWildcardIsMatch, 10) {
  Solution solution;
  EXPECT_TRUE(solution.isMatch("", "*"));
}

TEST(TestWildcardIsMatch, 11) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("", "?"));
}

TEST(TestWildcardIsMatch, 12) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("", "a"));
}
