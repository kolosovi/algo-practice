#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(JumpTest, 1) {
  Solution solution;
  std::vector<int> nums{2, 3, 1, 1, 4};
  EXPECT_EQ(solution.jump(nums), 2);
}
