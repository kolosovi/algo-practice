#include <gtest/gtest.h>

#include "solution.hpp"

#include <string>

TEST(TestDecodeString, 1) {
  Solution solution;
  std::string input{"3[a]2[bc]"};
  std::string expected{"aaabcbc"};
  EXPECT_EQ(solution.decodeString(input), expected);
}
