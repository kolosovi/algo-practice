#include <vector>
#include <algorithm>
#include <utility>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Less {
  bool operator()(const std::pair<int, int> &lhs,
                  const std::pair<int, int> &rhs) {
    return lhs.first > rhs.first ||
           (lhs.first == rhs.first && lhs.first >= rhs.first);
  }
};

class Iterator {
 public:
  int next() {
    auto top = min_heap_.front();
    std::pop_heap(min_heap_.begin(), min_heap_.end(), Less{});
    min_heap_.pop_back();
    lists_[top.second] = lists_[top.second]->next;
    if (lists_[top.second] != nullptr) {
      min_heap_.emplace_back(lists_[top.second]->val, top.second);
      std::push_heap(min_heap_.begin(), min_heap_.end(), Less{});
    }
    return top.first;
  }

  bool hasNext() const { return min_heap_.size() > 0; }

  Iterator(std::vector<ListNode *> lists) : lists_(lists) {
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i] == nullptr) {
        continue;
      }
      min_heap_.emplace_back(lists[i]->val, i);
      std::push_heap(min_heap_.begin(), min_heap_.end(), Less{});
    }
  }

 private:
  std::vector<ListNode *> lists_;
  std::vector<std::pair<int, int>> min_heap_;
};

class Solution {
 public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    Iterator it(lists);
    ListNode *result = nullptr, *cur = nullptr;
    while (it.hasNext()) {
      auto *node = new ListNode(it.next());
      if (cur != nullptr) {
        cur->next = node;
      } else {
        result = node;
      }
      cur = node;
    }
    return result;
  }
};
