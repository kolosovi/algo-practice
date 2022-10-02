#include <gtest/gtest.h>

#include "solution.hpp"

#include "testutil/file.hpp"

TEST(TestLaaksCSESWeirdAlgorithm, 1) {
  EXPECT_TRUE(
      testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}

TEST(TestLaaksCSESWeirdAlgorithm, 2) {
  EXPECT_TRUE(
      testutil::FileBasedTest(Solve, __FILE__, "2.txt", "2_expected.txt"));
}
