#pragma once

#include <array>
#include <cmath>
#include <istream>
#include <ostream>
#include <utility>

static constexpr char kU = 0, kD = 1, kL = 2, kR = 3, kNone = 4;
static constexpr char kDirCount = 4;
static constexpr int kSide = 7;
static constexpr int kCellCount = kSide * kSide;

static char kSym[kDirCount + 1]{'U', 'D', 'L', 'R', '?'};
static char tpl[kCellCount - 1];
static bool grid[kSide + 2][kSide + 2];

inline void CalcNextCell(char dir, int row, int col, int &next_row,
                         int &next_col) {
  next_row = row, next_col = col;
  if (dir == kU) {
    next_row--;
  } else if (dir == kD) {
    next_row++;
  } else if (dir == kL) {
    next_col--;
  } else {
    next_col++;
  }
}

void solve(int &count, int i, char prev, int row, int col) {
  if (i == kCellCount - 1) {
    if (row == kSide - 1 && col == 0) {
      count++;
    }
    return;
  }
  if (row == kSide - 1 && col == 0) {
    return;
  }
  int next_row, next_col, next_next_row, next_next_col, l_row, l_col, r_row,
      r_col;
  char left_dir, right_dir;
  for (char dir = kU; dir < kDirCount; dir++) {
    if (tpl[i] != kNone && dir != tpl[i]) {
      continue;
    }
    CalcNextCell(dir, row, col, next_row, next_col);
    if (grid[next_row + 1][next_col + 1]) {
      continue;
    }
    CalcNextCell(dir, next_row, next_col, next_next_row, next_next_col);
    if (grid[next_next_row + 1][next_next_col + 1]) {
      if (dir == kU || dir == kD) {
        left_dir = kL;
        right_dir = kR;
      } else {
        left_dir = kU;
        right_dir = kD;
      }
      CalcNextCell(left_dir, next_row, next_col, l_row, l_col);
      CalcNextCell(right_dir, next_row, next_col, r_row, r_col);
      if (!grid[l_row + 1][l_col + 1] && !grid[r_row + 1][r_col + 1]) {
        continue;
      }
    }
    grid[next_row + 1][next_col + 1] = true;
    solve(count, i + 1, dir, next_row, next_col);
    grid[next_row + 1][next_col + 1] = false;
  }
}

void Solve(std::istream &in, std::ostream &out) {
  for (int i = 0; i < kCellCount - 1; i++) {
    in >> tpl[i];
    if (tpl[i] == 'U') {
      tpl[i] = kU;
    } else if (tpl[i] == 'D') {
      tpl[i] = kD;
    } else if (tpl[i] == 'L') {
      tpl[i] = kL;
    } else if (tpl[i] == 'R') {
      tpl[i] = kR;
    } else {
      tpl[i] = kNone;
    }
  }
  for (int i = 0; i < kSide + 2; i++) {
    for (int j = 0; j < kSide + 2; j++) {
      if (i == 0 || j == 0 || i == kSide + 1 || j == kSide + 1) {
        grid[i][j] = true;
      } else {
        grid[i][j] = false;
      }
    }
  }
  int count = 0;
  grid[1][1] = true;
  solve(count, 0, kNone, 0, 0);
  out << count << '\n';
}
