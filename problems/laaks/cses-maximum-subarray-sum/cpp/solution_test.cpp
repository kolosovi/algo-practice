#include <gtest/gtest.h>

#include "solution.hpp"

#include "testutil/file.hpp"

TEST(TestLaaksCSESMaximumSubaraySum, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}

TEST(TestLaaksCSESMaximumSubaraySum, 2) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "2.txt", "2_expected.txt"));
}

TEST(TestLaaksCSESMaximumSubaraySum, 3) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "3.txt", "3_expected.txt"));
}
