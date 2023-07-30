#include <gtest/gtest.h>

#include <testutil/file.hpp>

#include "solution.hpp"

TEST(TestCppZeroCostConf232, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}

TEST(TestCppZeroCostConf232, 2) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "2.txt", "2_expected.txt"));
}

TEST(TestCppZeroCostConf232, 3) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "3.txt", "3_expected.txt"));
}

TEST(TestCppZeroCostConf232, 4) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "4.txt", "4_expected.txt"));
}
