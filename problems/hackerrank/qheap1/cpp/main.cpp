// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
#include <iostream>
#include <vector>
#include <utility>

class Heap {
 public:
  int Size() const { return heap_.size(); }

  int Top() const { return heap_[0]; }

  void Insert(int val) {
    heap_.push_back(val);
    bubble(heap_.size() - 1);
  }

  bool Remove(int val) {
    int i = 0;
    for (; i < heap_.size(); i++) {
      if (heap_[i] == val) {
        break;
      }
    }
    if (i == heap_.size()) {
      return false;
    }
    remove(i);
    return true;
  }

 private:
  std::vector<int> heap_;

  void bubble(int i) {
    while (i > 0 && heap_[i] < heap_[parent(i)]) {
      auto parent_i = parent(i);
      if (heap_[i] >= heap_[parent_i]) {
        return;
      }
      std::swap(heap_[i], heap_[parent_i]);
      i = parent_i;
    }
  }

  void min_heapify(int i) {
    if (i >= heap_.size()) {
      return;
    }
    while (true) {
      int smallest = i;
      auto left_i = left(i), right_i = right(i);
      if (left_i < heap_.size() && heap_[left_i] < heap_[smallest]) {
        smallest = left_i;
      }
      if (right_i < heap_.size() && heap_[right_i] < heap_[smallest]) {
        smallest = right_i;
      }
      if (smallest == i) {
        return;
      }
      std::swap(heap_[i], heap_[smallest]);
      i = smallest;
    }
  }

  void remove(int i) {
    if (i == heap_.size() - 1) {
      heap_.pop_back();
      return;
    }
    std::swap(heap_[i], heap_[heap_.size() - 1]);
    heap_.pop_back();
    min_heapify(i);
    bubble(i);
  }

  int parent(int i) { return ((i + 1) / 2) - 1; }

  int left(int i) { return 2 * i + 1; }

  int right(int i) { return 2 * i + 2; }
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  Heap heap;
  int num_queries = 0, query_type = 0, v = 0;
  std::cin >> num_queries;
  while (num_queries--) {
    std::cin >> query_type;
    if (query_type == 3) {
      std::cout << heap.Top() << "\n";
      continue;
    }
    std::cin >> v;
    if (query_type == 1) {
      heap.Insert(v);
    } else {
      heap.Remove(v);
    }
  }
  return 0;
}
