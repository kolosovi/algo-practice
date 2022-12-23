#pragma once

#include <unordered_map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *deleteDuplicatesUnsorted(ListNode *head) {
    std::unordered_map<int, int> freqs;
    for (auto *cur = head; cur != nullptr; cur = cur->next) {
      freqs[cur->val]++;
    }
    ListNode *last_kept = nullptr, *first_kept = nullptr;
    for (auto *cur = head; cur != nullptr; cur = cur->next) {
      if (freqs[cur->val] > 1) {
        continue;
      }
      if (last_kept != nullptr) {
        last_kept->next = cur;
      } else {
        first_kept = cur;
      }
      last_kept = cur;
    }
    if (last_kept != nullptr) {
      last_kept->next = nullptr;
    }
    return first_kept;
  }
};
