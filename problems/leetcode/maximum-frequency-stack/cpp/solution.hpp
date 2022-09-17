#pragma once

#include <algorithm>
#include <list>
#include <unordered_map>
#include <vector>

class FreqStack {
 public:
  FreqStack() : max_f_(0) {}

  void push(int val) {
    auto new_f = ++val_to_freq_[val];
    auto it = vals_.insert(vals_.end(), val);
    freq_to_stack_[new_f].push_back(it);
    max_f_ = std::max(max_f_, new_f);
  }

  int pop() {
    auto &stack = freq_to_stack_[max_f_];
    auto it = stack.back();
    auto val = *it;
    vals_.erase(it);
    auto new_f = --val_to_freq_[val];
    stack.pop_back();
    if (stack.size() == 0) {
      max_f_ = new_f;
    }
    return val;
  }

 private:
  int max_f_;
  std::list<int> vals_;
  std::unordered_map<int, std::vector<std::list<int>::iterator>> freq_to_stack_;
  std::unordered_map<int, int> val_to_freq_;
};
