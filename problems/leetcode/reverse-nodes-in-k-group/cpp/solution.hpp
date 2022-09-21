#pragma once

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    int n = 0;
    for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
      n++;
    }
    int end = n - (n % k);
    ListNode *cur_start = nullptr, *prev_start = nullptr;
    ListNode *prev = nullptr, *cur = head;
    ListNode *new_head = nullptr;
    for (int i = 0; i < end; i++) {
      auto pos = i % k;
      if (pos == 0) {
        prev_start = cur_start;
        cur_start = cur;
      }
      if (pos == k - 1) {
        if (i < k) {
          new_head = cur;
        }
        if (prev_start != nullptr) {
          prev_start->next = cur;
        }
      }
      auto next = cur->next;
      if (pos > 0) {
        cur->next = prev;
      }
      prev = cur;
      cur = next;
    }
    if (cur_start != nullptr) {
      cur_start->next = cur;
    }
    return new_head;
  }
};
