#include <gtest/gtest.h>

#include "solution.hpp"

#include <algorithm>
#include <string>
#include <vector>

TEST(StrobogrammaticNumberII, 1) {
  Solution solution;
  std::vector<std::string> expected{"0", "1", "8"};
  auto actual = solution.findStrobogrammatic(1);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(expected.size(), actual.size());
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]);
  }
}
