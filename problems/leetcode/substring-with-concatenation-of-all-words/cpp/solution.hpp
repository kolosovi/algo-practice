#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <utility>

static constexpr int kNoMatch = -1;

struct Node {
  Node() : parent(nullptr), suffix(nullptr), match_id(kNoMatch), letter('\0') {}

  std::unordered_map<char, Node *> children;
  Node *parent;
  Node *suffix;
  char letter;
  int match_id;
};

class Matcher {
 public:
  Matcher() = delete;
  Matcher(const std::vector<std::string> &words) : words_(words) {
    root_ = new Node();
    cur_ = root_;
    for (int id = 0; id < words_.size(); ++id) {
      auto *cur = root_;
      for (int i = 0; i < words_[id].size(); ++i) {
        Node *next = cur->children[words_[id][i]];
        if (next == nullptr) {
          next = new Node();
          next->parent = cur;
          next->letter = words_[id][i];
          cur->children[next->letter] = next;
        }
        if (i == words_[id].size() - 1) {
          next->match_id = id;
        }
        cur = next;
      }
    }
    std::vector<Node *> queue{root_};
    while (queue.size() > 0) {
      std::vector<Node *> next_queue;
      for (auto *node : queue) {
        if (node == root_) {
          node->suffix = nullptr;
        } else if (node->parent == root_) {
          node->suffix = root_;
        } else {
          Node *parent = node->parent;
          while (parent->suffix != nullptr &&
                 parent->suffix->children.count(node->letter) == 0) {
            parent = parent->parent;
          }
          if (parent->suffix == nullptr) {
            node->suffix = root_;
          } else {
            node->suffix = parent->suffix->children[node->letter];
          }
        }
        for (auto [letter, child] : node->children) {
          if (child == nullptr) {
            continue;
          }
          next_queue.push_back(child);
        }
      }
      std::swap(queue, next_queue);
    }
  }

  void Consume(char c) {
    for (Node *next = cur_->children[c];
         next != nullptr || cur_->suffix != nullptr;) {
      if (next != nullptr) {
        cur_ = next;
        break;
      }
      cur_ = cur_->suffix;
      next = cur_->children[c];
    }
  }

  bool IsMatchFound() const { return cur_->match_id != kNoMatch; }

  int MatchId() const { return cur_->match_id; }

 private:
  const std::vector<std::string> &words_;
  Node *cur_;
  Node *root_;
};

class Chain {
 public:
  Chain(std::vector<int> &target_freqs, int target_ids_size, int k)
      : target_freqs_(target_freqs),
        freqs_(target_freqs.size(), 0),
        match_count_(0),
        target_ids_size_(target_ids_size),
        k_(k) {}

  void Add(int id) {
    ids_.push_back(id);
    auto old_freq = freqs_[id]++;
    if (old_freq == target_freqs_[id]) {
      match_count_--;
    } else if (old_freq == target_freqs_[id] - 1) {
      match_count_++;
    }
    if (ids_.size() > target_ids_size_) {
      auto id_to_remove = ids_.front();
      auto old_freq = freqs_[id_to_remove]--;
      if (old_freq == target_freqs_[id_to_remove]) {
        match_count_--;
      } else if (old_freq == target_freqs_[id_to_remove] + 1) {
        match_count_++;
      }
      ids_.pop_front();
    }
  }

  bool IsComplete() const {
    return ids_.size() == target_ids_size_ &&
           match_count_ == target_freqs_.size();
  }

 private:
  std::deque<int> ids_;
  std::vector<int> &target_freqs_;
  std::vector<int> freqs_;
  int match_count_;
  int target_ids_size_;
  int k_;
};

class Solution {
 public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    std::vector<std::string> unique_words;
    std::vector<int> freqs;
    std::unordered_map<std::string, int> word_to_id;
    int k = 0;
    for (const auto word : words) {
      k = word.size();
      auto it = word_to_id.find(word);
      if (it != word_to_id.end()) {
        freqs[it->second]++;
        continue;
      }
      int id = unique_words.size();
      unique_words.push_back(word);
      freqs.push_back(1);
      word_to_id[word] = id;
    }
    std::unordered_map<int, Chain *> chains;
    Matcher matcher(unique_words);
    std::vector<int> result;
    for (int i = 0; i < s.size(); ++i) {
      auto letter = s[i];
      matcher.Consume(letter);
      if (!matcher.IsMatchFound()) {
        continue;
      }
      auto last_index = i - k;
      auto *chain = chains[last_index];
      if (chain == nullptr) {
        chain = new Chain(freqs, words.size(), k);
      }
      chain->Add(matcher.MatchId());
      if (chain->IsComplete()) {
        result.push_back(1 + i - words.size() * k);
      }
      chains[last_index] = nullptr;
      chains[i] = chain;
    }
    return result;
  }
};
