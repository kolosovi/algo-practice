#include <vector>
#include <algorithm>

struct Traverse {
  const std::vector<std::vector<int>> &matrix;
  std::vector<std::vector<int>> &visited;
  std::vector<std::vector<int>> &lengths;
  int &max;
  int numRows;
  int numCols;

  void traverse(int row, int col) {
    if (visited[row][col]) {
      return;
    }
    int maxChildLength = 0;
    if (col != 0 && matrix[row][col - 1] > matrix[row][col]) {
      traverse(row, col - 1);
      maxChildLength = std::max(maxChildLength, lengths[row][col - 1]);
    }
    if (col != numCols - 1 && matrix[row][col + 1] > matrix[row][col]) {
      traverse(row, col + 1);
      maxChildLength = std::max(maxChildLength, lengths[row][col + 1]);
    }
    if (row != 0 && matrix[row - 1][col] > matrix[row][col]) {
      traverse(row - 1, col);
      maxChildLength = std::max(maxChildLength, lengths[row - 1][col]);
    }
    if (row != numRows - 1 && matrix[row + 1][col] > matrix[row][col]) {
      traverse(row + 1, col);
      maxChildLength = std::max(maxChildLength, lengths[row + 1][col]);
    }
    visited[row][col] = 1;
    lengths[row][col] = 1 + maxChildLength;
    max = std::max(max, lengths[row][col]);
  }
};

class Solution {
 public:
  int longestIncreasingPath(std::vector<std::vector<int>> &matrix) {
    int numRows = matrix.size(), numCols = matrix[0].size();
    std::vector<int> row(numCols, 0);
    std::vector<std::vector<int>> visited(numRows, row);
    for (auto &item : row) {
      item = 1;
    }
    std::vector<std::vector<int>> lengths(numRows, row);
    int max = 0;
    Traverse traverser{matrix, visited, lengths, max, numRows, numCols};
    for (int row = 0; row < numRows; row++) {
      for (int col = 0; col < numCols; col++) {
        if (visited[row][col]) {
          continue;
        }
        traverser.traverse(row, col);
      }
    }
    return max;
  }
};
