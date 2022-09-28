#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>
#include <string>

TEST(TestFindSubstring, 1) {
  Solution solution;
  std::string s{"barfoothefoobarman"};
  std::vector<std::string> words{"foo", "bar"};
  std::vector<int> expected{0, 9};
  EXPECT_EQ(solution.findSubstring(s, words), expected);
}

TEST(TestFindSubstring, 2) {
  Solution solution;
  std::string s{"wordgoodwordbest"};
  std::vector<std::string> words{"word", "good", "best", "word"};
  std::vector<int> expected{0};
  EXPECT_EQ(expected.size(), 1);
  EXPECT_EQ(solution.findSubstring(s, words), expected);
}
