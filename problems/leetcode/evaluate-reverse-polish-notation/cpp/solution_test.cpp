#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>
#include <string>

TEST(EvalRPNTest, 1) {
  Solution solution;
  std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
  int expected = 9;
  EXPECT_EQ(solution.evalRPN(tokens), expected);
}

TEST(EvalRPNTest, 2) {
  Solution solution;
  std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
  int expected = 6;
  EXPECT_EQ(solution.evalRPN(tokens), expected);
}

TEST(EvalRPNTest, 3) {
  Solution solution;
  std::vector<std::string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                                     "/",  "*", "17", "+", "5", "+"};
  int expected = 22;
  EXPECT_EQ(solution.evalRPN(tokens), expected);
}
