#include <gtest/gtest.h>

#include "solution.hpp"

#include "testutil/file.hpp"

TEST(TestLaaksCSESTwoSets, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}
