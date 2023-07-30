#include <gtest/gtest.h>

#include <testutil/file.hpp>

#include "solution.hpp"

TEST(TestCppZeroCostConf231, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}

TEST(TestCppZeroCostConf232, 2) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "2.txt", "2_expected.txt"));
}

TEST(TestCppZeroCostConf233, 3) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "3.txt", "3_expected.txt"));
}
