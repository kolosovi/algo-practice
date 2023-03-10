#include <gtest/gtest.h>

#include <testutil/file.hpp>

#include "solution.hpp"

TEST(TestLaaksCSESSubarraySumsI, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}
