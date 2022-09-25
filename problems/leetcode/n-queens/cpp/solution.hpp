#pragma once

#include <string>
#include <vector>

static constexpr char kInvalidCol = -1;
static constexpr char kEmpty = '.';
static constexpr char kQueen = 'Q';

struct State {
  std::vector<char> placement;
  std::vector<bool> row_options;
  std::vector<bool> col_options;
  std::vector<bool> bl_ur_options;
  std::vector<bool> ul_br_options;
  int n;

  State(int n)
      : n(n),
        placement(n, kInvalidCol),
        row_options(n, true),
        col_options(n, true),
        bl_ur_options(2 * n - 1, true),
        ul_br_options(2 * n - 1, true) {}

  bool IsAvailable(int row, int col) const {
    return row_options[row] && col_options[col] &&
           bl_ur_options[ToBLUR(row, col)] && ul_br_options[ToULBR(row, col)];
  }

  void Put(int row, int col) {
    placement[row] = col;
    row_options[row] = false;
    col_options[col] = false;
    bl_ur_options[ToBLUR(row, col)] = false;
    ul_br_options[ToULBR(row, col)] = false;
  }

  void Clear(int row, int col) {
    placement[row] = kInvalidCol;
    row_options[row] = true;
    col_options[col] = true;
    bl_ur_options[ToBLUR(row, col)] = true;
    ul_br_options[ToULBR(row, col)] = true;
  }

  inline int ToBLUR(int row, int col) const { return row + col; }

  inline int ToULBR(int row, int col) const { return (n - 1 - row) + col; }
};

class Solution {
 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;
    State state(n);
    solve(state, result, 0);
    return result;
  }

 private:
  void solve(State &state, std::vector<std::vector<std::string>> &result,
             int row) {
    if (row == state.n) {
      std::string empty_board_row(state.n, kEmpty);
      std::vector<std::string> board(state.n, empty_board_row);
      for (int i = 0; i < state.n; ++i) {
        board[i][state.placement[i]] = kQueen;
      }
      result.push_back(std::move(board));
      return;
    }
    for (int col = 0; col < state.n; col++) {
      if (!state.IsAvailable(row, col)) {
        continue;
      }
      state.Put(row, col);
      solve(state, result, row + 1);
      state.Clear(row, col);
    }
  }
};
