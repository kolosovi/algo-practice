#include <gtest/gtest.h>

#include "solution.hpp"

#include "testutil/file.hpp"

TEST(TestLaaksCSESPermutations, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}

TEST(TestLaaksCSESPermutations, 2) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "2.txt", "2_expected.txt"));
}

TEST(TestLaaksCSESPermutations, 3) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "3.txt", "3_expected.txt"));
}

TEST(TestLaaksCSESPermutations, 4) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "4.txt", "4_expected.txt"));
}

TEST(TestLaaksCSESPermutations, 5) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "5.txt", "5_expected.txt"));
}

TEST(TestLaaksCSESPermutations, 6) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "6.txt", "6_expected.txt"));
}

TEST(TestLaaksCSESPermutations, 7) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "7.txt", "7_expected.txt"));
}

TEST(TestLaaksCSESPermutations, 8) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "8.txt", "8_expected.txt"));
}
