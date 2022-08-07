#pragma once

#include <array>
#include <string>
#include <utility>
#include <vector>

static std::array<std::pair<int, int>, 4> directions = {std::make_pair(1, 0), {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (char row = 0; row < board.size(); row++) {
            for (char col = 0; col < board.front().size(); col++) {
                if (visit(board, word, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool visit(std::vector<std::vector<char>>& board, const std::string &word, char row, char col, char i) {
        if (board[row][col] < 'A') {
            return false;
        }
        if (word[i] != board[row][col]) {
            return false;
        }
        if (i == word.size() - 1) {
            return true;
        }
        board[row][col] -= 'A';
        for (auto [row_diff, col_diff] : directions) {
            auto new_row = row + row_diff, new_col = col + col_diff;
            if (new_row < 0 || new_col < 0 || new_row == board.size() || new_col == board.front().size()) {
                continue;
            }
            if (visit(board, word, new_row, new_col, i+1)) {
                return true;
            }
        }
        board[row][col] += 'A';
        return false;
    }
};
