#include <gtest/gtest.h>

#include "solution.hpp"

TEST(TestIsMatch, 1) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("aabb", "a*"));
}

TEST(TestIsMatch, 2) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("aabb", "a*b"));
}

TEST(TestIsMatch, 3) {
  Solution solution;
  EXPECT_TRUE(solution.isMatch("aabb", "a*bb"));
}

TEST(TestIsMatch, 4) {
  Solution solution;
  EXPECT_TRUE(solution.isMatch("aabb", ".*b"));
}

TEST(TestIsMatch, 5) {
  Solution solution;
  EXPECT_TRUE(solution.isMatch("aabb", "a*.*"));
}

TEST(TestIsMatch, 6) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("aa", "a"));
}

TEST(TestIsMatch, 7) {
  Solution solution;
  EXPECT_TRUE(solution.isMatch("aa", "aa"));
}

TEST(TestIsMatch, 8) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("aaa", "ab*a"));
}

TEST(TestIsMatch, 9) {
  Solution solution;
  EXPECT_FALSE(solution.isMatch("bccbbabcaccacbcacaa", ".*b.*c*.*.*.c*a*.c"));
}
