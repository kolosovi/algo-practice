#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
How do I know it's DP?

1. there are overlapping subproblems (e.g. segmentations AABB.... and ABBB...
lead to the same subproblem)
2. optimal solution for the problem can be constructed from optimal solutions to
subproblems. This is true because if I have segmentation AABB... and I know that
... can/cannot be segmented I also know the solution to the AABB... problem.

The three components of a DP solution are
1. state variables
2. state transition function (i.e. recurrence relation)
3. base case(s)

Here the state variable is the # of chars that we've successfully segmented so
far. So dp(0) is the solution to the original problem.

The base case is dp(N) where N is the size of the string: dp(N) is `true`.

The transition function?
A-ha, I see why this problem shows up in "iteration in the recurrence relation"
pattern because: dp(i) is true <=> a word `w` exists such that dp(i + len_w) is
true.

So the "algorithm" is
mem[i] = false
for w in words:
    if dp(i + len_w) is true:
        mem[i] = true
return mem[i]

An option is to use a Trie and keep iterating until possible. This gives an
O(N^2) solution.

The alternative? An exponentially complex solution.
*/

class Trie {
 public:
  Trie() : children_(), is_terminal_(false) {}

  void Add(const std::string &word) {
    Trie *cur = this;
    for (auto ch : word) {
      if (cur->children_.count(ch)) {
        cur = cur->children_[ch];
        continue;
      }
      auto *next = new Trie();
      cur->children_[ch] = next;
      cur = next;
    }
    cur->is_terminal_ = true;
  }

  bool IsTerminal() const { return is_terminal_; }

  Trie *Next(char ch) const {
    auto it = children_.find(ch);
    return it != children_.end() ? it->second : nullptr;
  }

 private:
  std::unordered_map<char, Trie *> children_;
  bool is_terminal_;
};

class Solution {
 public:
  bool wordBreak(string s, std::vector<std::string> &wordDict) {
    this->s = s;
    mem.resize(s.size());
    for (auto &cell : mem) {
      cell = -1;
    }
    words = new Trie();
    for (const auto &word : wordDict) {
      words->Add(word);
    }
    return dp(0);
  }

 private:
  std::string s;
  std::vector<int> mem;
  Trie *words;

  bool dp(int i) {
    if (i == s.size()) {
      return true;
    }
    if (mem[i] == -1) {
      mem[i] = 0;
      auto *cur = words;
      for (int j = i; j < s.size(); j++) {
        cur = cur->Next(s[j]);
        if (cur == nullptr) {
          break;
        }
        if (cur->IsTerminal() && dp(j + 1)) {
          mem[i] = 1;
        }
      }
    }
    return mem[i] == 0 ? false : true;
  }
};

class Solution1 {
 public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    std::unordered_set<std::string> dict;
    for (auto &word : wordDict) {
      dict.insert(std::move(word));
    }
    std::vector<int> mem(s.size(), -1);
    return wordBreak(s, dict, mem, 0);
  }

  bool wordBreak(const std::string &s,
                 const std::unordered_set<std::string> &dict,
                 std::vector<int> &mem, int start) {
    if (mem[start] != -1) {
      return mem[start] == 1;
    }
    std::string prefix;
    for (int i = start; i < s.size(); i++) {
      prefix.push_back(s[i]);
      if (!dict.count(prefix)) {
        continue;
      }
      if (i == s.size() - 1 || wordBreak(s, dict, mem, i + 1)) {
        mem[start] = 1;
        return true;
      }
    }
    mem[start] = 0;
    return false;
  }
};
