#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

namespace {
ListNode *Cons(int x, ListNode *tail) { return new ListNode(x, tail); }

ListNode *Cons(int x) { return new ListNode(x); }
}  // namespace

TEST(ReverseKGroup, 1) {
  Solution solution;
  ListNode *head = Cons(1, Cons(2, Cons(3, Cons(4, Cons(5)))));
  std::vector<int> expected{2, 1, 4, 3, 5};
  auto *new_head = solution.reverseKGroup(head, 2);
  auto *cur = new_head;
  for (auto num : expected) {
    EXPECT_EQ(cur->val, num);
    cur = cur->next;
  }
  EXPECT_EQ(cur, nullptr);
}
