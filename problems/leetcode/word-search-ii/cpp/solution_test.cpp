#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>
#include <string>

TEST(TestWordSearchII, 1) {
  Solution solution;
  std::vector<std::vector<char>> board{{'o', 'a', 'a', 'n'},
                                       {'e', 't', 'a', 'e'},
                                       {'i', 'h', 'k', 'r'},
                                       {'i', 'f', 'l', 'v'}};
  std::vector<std::string> words{"oath", "pea", "eat", "rain"};
  std::vector<std::string> expected{"eat", "oath"};
  auto actual = solution.findWords(board, words);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(expected.size(), actual.size());
  for (int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]);
  }
}
