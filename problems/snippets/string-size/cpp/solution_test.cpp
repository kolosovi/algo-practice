#include <gtest/gtest.h>

#include <testutil/file.hpp>

#include "solution.hpp"

TEST(TestSnippetsStringSize, 1) {
  GTEST_SKIP() << "Intentionally fails";
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}

TEST(TestSnippetsStringSize, 2) {
  GTEST_SKIP() << "Intentionally fails";
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "2.txt", "2_expected.txt"));
}
