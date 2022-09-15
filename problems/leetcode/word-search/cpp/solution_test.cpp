#include <gtest/gtest.h>

#include "solution.hpp"

#include <string>
#include <vector>

TEST(ExistTest, 1) {
  Solution solution;
  std::vector<std::vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::string word{"ABCCED"};
  EXPECT_TRUE(solution.exist(board, word));
}
