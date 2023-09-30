#pragma once

#include <vector>
#include <string>
#include <utility>

using namespace std;

static const int kNone = -1;

struct Trie {
  Trie* children[26];
  int index;

  Trie() {
    index = kNone;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }

  void Add(const string& word, int index) {
    auto* node = this;
    for (auto letter : word) {
      auto* child = node->children[letter - 'a'];
      if (child != nullptr) {
        node = child;
        continue;
      }
      child = new Trie();
      node->children[letter - 'a'] = child;
      node = child;
    }
    node->index = index;
  }
};

static const vector<pair<int, int>> moves{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Visitor {
  vector<vector<char>>& board;
  vector<string>& words;
  vector<bool> found_map;
  string path;

  Visitor(vector<vector<char>>& board, vector<string>& words)
      : board(board), words(words), found_map(words.size(), false) {}

  void visit_inner(Trie* root, int row, int col) {
    if (root->index != kNone) {
      found_map[root->index] = true;
    }
    for (auto [drow, dcol] : moves) {
      auto new_row = row + drow, new_col = col + dcol;
      if (new_row < 0 || new_row >= board.size() || new_col < 0 ||
          new_col >= board.front().size()) {
        continue;
      }
      Visit(root, new_row, new_col);
    }
  }

  void Visit(Trie* root, int row, int col) {
    if (board[row][col] == 0) {
      return;
    }
    auto* child = root->children[board[row][col] - 'a'];
    if (child == nullptr) {
      return;
    }
    auto orig_char = board[row][col];
    board[row][col] = 0;
    path.push_back(board[row][col]);
    visit_inner(child, row, col);
    board[row][col] = orig_char;
    path.pop_back();
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    auto* trie = new Trie();
    for (int i = 0; i < words.size(); i++) {
      trie->Add(words[i], i);
    }
    Visitor visitor{board, words};
    for (int row = 0; row < board.size(); ++row) {
      for (int col = 0; col < board.front().size(); ++col) {
        visitor.Visit(trie, row, col);
      }
    }
    vector<string> result;
    for (int i = 0; i < visitor.found_map.size(); i++) {
      if (visitor.found_map[i]) {
        result.push_back(words[i]);
      }
    }
    return result;
  }
};
