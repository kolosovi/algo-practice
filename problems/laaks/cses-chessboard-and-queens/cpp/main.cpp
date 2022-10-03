// This code was generated, do not edit.

#include <iostream>

#include <cstring>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

static constexpr char kFree = '.';
static constexpr char kReserved = '*';
static constexpr int kSize = 8;

int search(const std::vector<std::string> &board, int row, char *row_opts,
           char *col_opts, char *maj_diag_opts, char *min_diag_opts) {
  if (row == kSize) {
    return 1;
  }
  if (row_opts[row]) {
    return 0;
  }
  int sum = 0;
  for (int col = 0; col < kSize; col++) {
    if (col_opts[col]) {
      continue;
    }
    if (board[row][col] == kReserved) {
      continue;
    }
    int maj_diag = kSize - 1 + col - row;
    if (maj_diag_opts[maj_diag]) {
      continue;
    }
    int min_diag = row + col;
    if (min_diag_opts[min_diag]) {
      continue;
    }
    row_opts[row]++;
    col_opts[col]++;
    maj_diag_opts[maj_diag]++;
    min_diag_opts[min_diag]++;
    sum += search(board, row + 1, row_opts, col_opts, maj_diag_opts,
                  min_diag_opts);
    row_opts[row]--;
    col_opts[col]--;
    maj_diag_opts[maj_diag]--;
    min_diag_opts[min_diag]--;
  }
  return sum;
}

void Solve(std::istream &in, std::ostream &out) {
  std::string line;
  std::vector<std::string> board;
  while (std::getline(in, line)) {
    board.push_back(line);
  }
  char row_opts[kSize];
  char col_opts[kSize];
  char maj_diag_opts[2 * kSize - 1];
  char min_diag_opts[2 * kSize - 1];
  for (int i = 0; i < kSize; ++i) {
    row_opts[i] = 0;
    col_opts[i] = 0;
  }
  for (int i = 0; i < 2 * kSize - 1; ++i) {
    maj_diag_opts[i] = 0;
    min_diag_opts[i] = 0;
  }
  auto result =
      search(board, 0, row_opts, col_opts, maj_diag_opts, min_diag_opts);
  out << result << '\n';
}

int main() { Solve(std::cin, std::cout); }
