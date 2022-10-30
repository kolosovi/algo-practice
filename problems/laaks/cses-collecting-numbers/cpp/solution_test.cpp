#include <gtest/gtest.h>

#include <testutil/file.hpp>

#include "solution.hpp"

TEST(TestLaaksCSESCollectingNumbers, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}

TEST(TestLaaksCSESCollectingNumbers, 2) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "2.txt", "2_expected.txt"));
}

TEST(TestLaaksCSESCollectingNumbers, 3) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "3.txt", "3_expected.txt"));
}

TEST(TestLaaksCSESCollectingNumbers, 4) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "4.txt", "4_expected.txt"));
}

TEST(TestLaaksCSESCollectingNumbers, 5) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "5.txt", "5_expected.txt"));
}

TEST(TestLaaksCSESCollectingNumbers, 6) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "6.txt", "6_expected.txt"));
}

TEST(TestLaaksCSESCollectingNumbers, 7) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "7.txt", "7_expected.txt"));
}

TEST(TestLaaksCSESCollectingNumbers, 8) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "8.txt", "8_expected.txt"));
}

TEST(TestLaaksCSESCollectingNumbers, 9) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "9.txt", "9_expected.txt"));
}
