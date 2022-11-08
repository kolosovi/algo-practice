#include <gtest/gtest.h>

#include <testutil/file.hpp>

#include "solution.hpp"

TEST(TestLaaksCSESRoomAllocation, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}

TEST(TestLaaksCSESRoomAllocation, 2) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "2.txt", "2_expected.txt"));
}
