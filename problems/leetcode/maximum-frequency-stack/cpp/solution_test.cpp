#include <gtest/gtest.h>

#include "solution.hpp"

TEST(TestFreqStack, 1) {
  FreqStack stack;
  auto &stack_ref = stack;
  stack.push(5);
  stack.push(7);
  stack.push(5);
  stack.push(7);
  stack.push(4);
  stack.push(5);
  int val;
  val = stack.pop();
  EXPECT_EQ(val, 5);
  val = stack.pop();
  EXPECT_EQ(val, 7);
  val = stack.pop();
  EXPECT_EQ(val, 5);
  val = stack.pop();
  EXPECT_EQ(val, 4);
}
