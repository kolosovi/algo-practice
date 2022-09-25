#pragma once

#include <vector>
#include <unordered_set>

static constexpr std::size_t kSize = 9;
static constexpr char kEmpty = '.';
static constexpr char kOne = '1';
static constexpr char kNine = '9';

inline int ToBox(int row, int col) { return (row - (row % 3)) + (col / 3); }

inline int ToIndex(char value) { return value - kOne; }

inline std::pair<int, int> Next(int row, int col) {
  if (col < kSize - 1) {
    return {row, col + 1};
  }
  return {row + 1, 0};
}

struct State {
  std::array<std::array<bool, kSize>, kSize> row_options;
  std::array<std::array<bool, kSize>, kSize> col_options;
  std::array<std::array<bool, kSize>, kSize> box_options;
};

class Solution {
 public:
  void solveSudoku(std::vector<std::vector<char>> &board) {
    State state;
    for (int i = 0; i < kSize; i++) {
      for (char num = kOne; num <= kNine; num++) {
        state.row_options[i][ToIndex(num)] = true;
        state.col_options[i][ToIndex(num)] = true;
        state.box_options[i][ToIndex(num)] = true;
      }
    }
    for (int row = 0; row < kSize; row++) {
      for (int col = 0; col < kSize; col++) {
        if (board[row][col] == kEmpty) {
          continue;
        }
        state.row_options[row][ToIndex(board[row][col])] = false;
        state.col_options[col][ToIndex(board[row][col])] = false;
        state.box_options[ToBox(row, col)][ToIndex(board[row][col])] = false;
      }
    }
    Solve(board, state, 0, 0);
  }

 private:
  bool Solve(std::vector<std::vector<char>> &board, State &state, int row,
             int col) {
    if (board[row][col] != kEmpty) {
      if (row == kSize - 1 && col == kSize - 1) {
        return true;
      }
      auto [next_row, next_col] = Next(row, col);
      return Solve(board, state, next_row, next_col);
    }
    for (char num = kOne; num <= kNine; ++num) {
      if (!IsAvailable(board, state, row, col, num)) {
        continue;
      }
      Put(board, state, row, col, num);
      if (row == kSize - 1 && col == kSize - 1) {
        return true;
      }
      auto [next_row, next_col] = Next(row, col);
      auto is_solved = Solve(board, state, next_row, next_col);
      if (is_solved) {
        return true;
      }
      Erase(board, state, row, col);
    }
    return false;
  }

  bool IsAvailable(std::vector<std::vector<char>> &board, State &state, int row,
                   int col, char num) {
    if (!state.row_options[row][ToIndex(num)]) {
      return false;
    }
    if (!state.col_options[col][ToIndex(num)]) {
      return false;
    }
    if (!state.box_options[ToBox(row, col)][ToIndex(num)]) {
      return false;
    }
    return true;
  }

  void Put(std::vector<std::vector<char>> &board, State &state, int row,
           int col, char value) {
    board[row][col] = value;
    state.row_options[row][ToIndex(board[row][col])] = false;
    state.col_options[col][ToIndex(board[row][col])] = false;
    state.box_options[ToBox(row, col)][ToIndex(board[row][col])] = false;
  }

  void Erase(std::vector<std::vector<char>> &board, State &state, int row,
             int col) {
    state.row_options[row][ToIndex(board[row][col])] = true;
    state.col_options[col][ToIndex(board[row][col])] = true;
    state.box_options[ToBox(row, col)][ToIndex(board[row][col])] = true;
    board[row][col] = kEmpty;
  }
};
