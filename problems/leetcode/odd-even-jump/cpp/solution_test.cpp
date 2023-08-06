#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(OddEvenJump, 1) {
  Solution solution;
  std::vector<int> arr{10, 13, 12, 14, 15};
  EXPECT_EQ(solution.oddEvenJumps(arr), 2);
}

TEST(OddEvenJump, 2) {
  Solution solution;
  std::vector<int> arr{2, 3, 1, 1, 4};
  EXPECT_EQ(solution.oddEvenJumps(arr), 3);
}

TEST(OddEvenJump, 3) {
  Solution solution;
  std::vector<int> arr{5, 1, 3, 4, 2};
  EXPECT_EQ(solution.oddEvenJumps(arr), 3);
}
