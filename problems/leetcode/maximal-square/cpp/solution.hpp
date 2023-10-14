#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximalSquare(std::vector<std::vector<char>> &matrix) {
    if (matrix.size() == 0) {
      return 0;
    }
    num_rows = matrix.size(), num_cols = matrix.back().size();
    mem.resize(num_rows);
    for (auto &memrow : mem) {
      memrow.resize(num_cols);
      for (auto &memcell : memrow) {
        memcell = -1;
      }
    }
    this->matrix = matrix;
    max = 0;
    max = std::max(max, dp(0, 0));
    return max * max;
  }

 private:
  int dp(int row, int col) {
    if (row == num_rows || col == num_cols) {
      return 0;
    }
    if (mem[row][col] == -1) {
      int lower_area = dp(row + 1, col);
      int right_area = dp(row, col + 1);
      int lower_right_area = dp(row + 1, col + 1);
      if (matrix[row][col] == '0') {
        mem[row][col] = 0;
      } else {
        mem[row][col] =
            1 + std::min({lower_area, right_area, lower_right_area});
      }
    }
    max = std::max(max, mem[row][col]);
    return mem[row][col];
  }

  int num_rows;
  int num_cols;
  int max;
  std::vector<std::vector<int>> mem;
  std::vector<std::vector<char>> matrix;
};
