#include <gtest/gtest.h>

#include "solution.hpp"

#include <string>

TEST(TestRemoveDuplicatesFromAnUnsortedLinkedList, 1) {
  Solution solution;
  ListNode *input =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2))));
  auto *output = solution.deleteDuplicatesUnsorted(input);
  EXPECT_FALSE(output == nullptr);
  EXPECT_EQ(output->val, 1);
  EXPECT_FALSE(output->next == nullptr);
  EXPECT_EQ(output->next->val, 3);
  EXPECT_TRUE(output->next->next == nullptr);
}
