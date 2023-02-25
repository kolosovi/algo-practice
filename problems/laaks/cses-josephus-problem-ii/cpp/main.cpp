// This code was generated, do not edit.

#include <iostream>

#include <istream>
#include <ostream>

template <class K, class Compare>
class Set {
 private:
  enum Color { RED, BLACK };

 public:
  class Node {
    friend class Set;

   public:
    K Key() { return key_; }

   private:
    Node()
        : parent_(nullptr),
          left_(nullptr),
          right_(nullptr),
          size_(0),
          color_(BLACK) {}

    Node(Node *parent, Node *left, Node *right, K key)
        : parent_(parent),
          left_(left),
          right_(right),
          key_(key),
          size_(1),
          color_(RED) {}

    Node *parent_;
    Node *left_;
    Node *right_;
    K key_;
    int size_;
    Color color_;
  };

  Set() : cmp_(), nil_(new Node()), root_(nil_) {}

  void Insert(K key) {}

  Node *Select(int offset) { return nullptr; }

  void Delete(Node *node) {}

  int Size() const {
    if (root_ == nil_) {
      return 0;
    }
    return root_->size_;
  }

 private:
  Compare cmp_;
  Node *nil_;
  Node *root_;
};

void Solve(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  Set<int, std::less<int>> set;
  for (int child = 1; child <= n; child++) {
    set.Insert(child);
  }
  int offset = k % n;
  while (set.Size() > 0) {
    auto *it = set.Select(offset);
    if (set.Size() < n) {
      out << ' ';
    }
    out << it->Key();
    set.Delete(it);
    offset = (offset + k) % set.Size();
  }
  out << '\n';
}

int main() { Solve(std::cin, std::cout); }
