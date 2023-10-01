#include <gtest/gtest.h>

#include "solution.hpp"

TEST(TestAndroidUnlockPatterns, 1) {
  Solution solution;
  EXPECT_EQ(389497, solution.numberOfPatterns(1, 9));
}
