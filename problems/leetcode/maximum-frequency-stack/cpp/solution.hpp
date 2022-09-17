#pragma once

#include <unordered_map>
#include <vector>

class FreqStack {
 public:
  FreqStack() {}

  void push(int val) {
    auto new_f = ++val_to_freq_[val];
    if (new_f > stacks_.size()) {
      stacks_.resize(new_f);
    }
    stacks_[new_f - 1].emplace_back(val);
  }

  int pop() {
    auto &stack = stacks_.back();
    auto val = stack.back();
    --val_to_freq_[val];
    stack.pop_back();
    if (stack.size() == 0) {
      stacks_.pop_back();
    }
    return val;
  }

 private:
  std::vector<std::vector<int>> stacks_;
  std::unordered_map<int, int> val_to_freq_;
};
