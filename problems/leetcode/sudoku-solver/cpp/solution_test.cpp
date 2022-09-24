#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

namespace {
static const int kBoardSize = 9;
}

TEST(TestSolveSudokuToBox, 1) {
  for (int row = 0; row < kSize; ++row) {
    for (int col = 0; col < kSize; ++col) {
      auto box = ToBox(row, col);
      EXPECT_GE(box, 0);
      EXPECT_LE(box, 8);
      if (row <= 2) {
        if (col <= 2) {
          EXPECT_EQ(box, 0);
        } else if (col <= 5) {
          EXPECT_EQ(box, 1);
        } else {
          EXPECT_EQ(box, 2);
        }
      } else if (row <= 5) {
        if (col <= 2) {
          EXPECT_EQ(box, 3);
        } else if (col <= 5) {
          EXPECT_EQ(box, 4);
        } else {
          EXPECT_EQ(box, 5);
        }
      } else {
        if (col <= 2) {
          EXPECT_EQ(box, 6);
        } else if (col <= 5) {
          EXPECT_EQ(box, 7);
        } else {
          EXPECT_EQ(box, 8);
        }
      }
    }
  }
}

TEST(TestSolveSudokuNext, 1) {
  auto [row, col] = Next(0, 0);
  EXPECT_EQ(row, 0);
  EXPECT_EQ(col, 1);
}

TEST(TestSolveSudokuNext, 2) {
  auto [row, col] = Next(0, 1);
  EXPECT_EQ(row, 0);
  EXPECT_EQ(col, 2);
}

TEST(TestSolveSudokuNext, 3) {
  auto [row, col] = Next(0, 8);
  EXPECT_EQ(row, 1);
  EXPECT_EQ(col, 0);
}

TEST(TestSolveSudoku, 1) {
  Solution solution;
  std::vector<std::vector<char>> input{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  auto &output = input;
  std::vector<std::vector<char>> expected{
      {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
      {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
      {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
      {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
      {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
      {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
      {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
      {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
      {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
  solution.solveSudoku(input);
  EXPECT_EQ(expected.size(), kBoardSize);
  EXPECT_EQ(output.size(), kBoardSize);
  for (int row_i = 0; row_i < kBoardSize; row_i++) {
    const auto &output_row = output[row_i];
    const auto &expected_row = expected[row_i];
    EXPECT_EQ(expected_row.size(), kBoardSize);
    EXPECT_EQ(output_row.size(), kBoardSize);
    EXPECT_EQ(output_row, expected_row);
  }
}
