#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>
#include <string>

TEST(GenerateParentheses, 1) {
  Solution solution;
  std::vector<std::string> expected{"((()))", "(()())", "(())()", "()(())",
                                    "()()()"};
  auto actual = solution.generateParenthesis(3);
  EXPECT_EQ(expected.size(), actual.size());
  for (int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]);
  }
}
