#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(FindAnagramsTest, 1) {
  Solution solution;
  std::vector<int> expected{0, 6};
  EXPECT_EQ(solution.findAnagrams("cbaebabacd", "abc"), expected);
}
