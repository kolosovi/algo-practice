#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>
#include <string>

TEST(TestPalindromePairs, 1) {
  Solution solution;
  std::vector<std::string> words{"abcd", "dcba", "lls", "s", "sssll", ""};
  std::vector<std::vector<int>> expected{{0, 1}, {1, 0}, {3, 2},
                                         {3, 5}, {5, 3}, {2, 4}};
  EXPECT_EQ(solution.palindromePairs(words), expected);
}
