#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>
#include <string>

TEST(FindAndReplaceInString, 1) {
  Solution solution;
  std::vector<int> indices{0, 2};
  std::vector<std::string> sources{"a", "cd"}, targets{"eee", "fff"};
  EXPECT_EQ(solution.findReplaceString("abcd", indices, sources, targets),
            "eeebfff");
}
