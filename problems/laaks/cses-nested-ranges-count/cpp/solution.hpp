#pragma once

#include <algorithm>
#include <istream>
#include <numeric>
#include <ostream>
#include <utility>
#include <vector>

enum class Color : bool { kBlack = 0, kRed = 1 };

template <class Key>
struct Node {
  Node<Key> *parent;
  Node<Key> *left;
  Node<Key> *right;
  int size;
  int factor;
  Key key;
  Color color;

  Node()
      : parent(nullptr),
        left(nullptr),
        right(nullptr),
        size(0),
        factor(0),
        key(),
        color(Color::kBlack) {}

  Node(Key key, Node<Key> *parent, Node<Key> *left, Node<Key> *right)
      : parent(parent),
        left(left),
        right(right),
        size(1),
        factor(1),
        key(key),
        color(Color::kRed) {}

  bool IsRed() const { return color == Color::kRed; }
};

template <class Key, class Compare>
class Set {
 public:
  Set() : cmp_(), nil_(new Node<Key>()), root_(nil_) {}

  void Insert(Key key) {
    auto *parent = nil_;
    auto *place = root_;
    while (place != nil_) {
      parent = place;
      parent->size++;
      if (cmp_(key, place->key)) {
        place = place->left;
      } else if (cmp_(place->key, key)) {
        place = place->right;
      } else {
        place->factor++;
        return;
      }
    }
    auto *newbie = new Node<Key>(key, parent, nil_, nil_);
    if (parent == nil_) {
      root_ = newbie;
    } else if (cmp_(newbie->key, parent->key)) {
      parent->left = newbie;
    } else {
      parent->right = newbie;
    }
    insertFixup(newbie);
  }

  Node<Key> *UpperBound(Key key) const {
    Node<Key> *last = nil_, *cur = root_;
    while (cur != nil_) {
      last = cur;
      if (cmp_(key, cur->key)) {
        cur = cur->left;
      } else if (cmp_(cur->key, key)) {
        cur = cur->right;
      } else {
        break;
      }
    }
    if (last == nil_ || cmp_(key, last->key)) {
      return last;
    }
    return succ(last);
  }

  int Rank(Node<Key> *node) const {
    int rank = node->left->size;
    for (auto *child = node; child != root_; child = child->parent) {
      if (child == child->parent->right) {
        rank += child->parent->left->size + child->parent->factor;
      }
    }
    return rank;
  }

  int Size() const { return root_->size; }

  int UpperBoundRank(Key key) const {
    auto *bound = UpperBound(key);
    if (bound != nil_) {
      return Rank(bound);
    }
    return Size();
  }

 private:
  Compare cmp_;
  Node<Key> *nil_;
  Node<Key> *root_;

  void insertFixup(Node<Key> *node) {
    while (node->parent->IsRed()) {
      if (node->parent == node->parent->parent->left) {
        auto *uncle = node->parent->parent->right;
        if (uncle->IsRed()) {
          node->parent->color = Color::kBlack;
          uncle->color = Color::kBlack;
          node->parent->parent->color = Color::kRed;
          node = node->parent->parent;
        } else {
          if (node == node->parent->right) {
            node = node->parent;
            leftRotate(node);
          }
          node->parent->color = Color::kBlack;
          node->parent->parent->color = Color::kRed;
          rightRotate(node->parent->parent);
        }
      } else {
        auto *uncle = node->parent->parent->left;
        if (uncle->IsRed()) {
          node->parent->color = Color::kBlack;
          uncle->color = Color::kBlack;
          node->parent->parent->color = Color::kRed;
          node = node->parent->parent;
        } else {
          if (node == node->parent->left) {
            node = node->parent;
            rightRotate(node);
          }
          node->parent->color = Color::kBlack;
          node->parent->parent->color = Color::kRed;
          leftRotate(node->parent->parent);
        }
      }
    }
    root_->color = Color::kBlack;
  }

  void leftRotate(Node<Key> *node) {
    auto *replacement = node->right;
    node->right = replacement->left;
    replacement->size = node->size;
    node->size = node->factor + node->left->size + node->right->size;
    if (replacement->left != nil_) {
      replacement->left->parent = node;
    }
    replacement->parent = node->parent;
    if (node->parent == nil_) {
      root_ = replacement;
    } else if (node == node->parent->left) {
      node->parent->left = replacement;
    } else {
      node->parent->right = replacement;
    }
    replacement->left = node;
    node->parent = replacement;
  }

  void rightRotate(Node<Key> *node) {
    auto *replacement = node->left;
    node->left = replacement->right;
    replacement->size = node->size;
    node->size = node->factor + node->left->size + node->right->size;
    if (replacement->right != nil_) {
      replacement->right->parent = node;
    }
    replacement->parent = node->parent;
    if (node->parent == nil_) {
      root_ = replacement;
    } else if (node == node->parent->left) {
      node->parent->left = replacement;
    } else {
      node->parent->right = replacement;
    }
    replacement->right = node;
    node->parent = replacement;
  }

  Node<Key> *succ(Node<Key> *last) const {
    if (last->right != nil_) {
      return min(last->right);
    }
    auto *parent = last->parent, *child = last;
    while (parent != nil_ && parent->left != child) {
      child = parent;
      parent = parent->parent;
    }
    return parent;
  }

  Node<Key> *min(Node<Key> *node) const {
    for (; node->left != nil_; node = node->left) {
    }
    return node;
  }
};

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::pair<int, int>> ranges;
  std::vector<int> indexes(n);
  std::iota(indexes.begin(), indexes.end(), 0);
  std::vector<int> contained_in_counts(n, 0), contains_counts(n, 0);
  for (int i = 0; i < n; i++) {
    std::pair<int, int> range;
    in >> range.first >> range.second;
    ranges.push_back(std::move(range));
  }
  // Sort by lower end DESC, upper end ASC
  std::sort(indexes.begin(), indexes.end(),
            [&ranges](const int &lhs_i, const int &rhs_i) {
              const auto &lhs = ranges[lhs_i], &rhs = ranges[rhs_i];
              if (lhs.first > rhs.first) {
                return true;
              }
              if (lhs.first == rhs.first) {
                return lhs.second < rhs.second;
              }
              return false;
            });
  Set<int, std::less<int>> upper_ends_ASC;
  for (auto it = indexes.begin(); it != indexes.end(); ++it) {
    contains_counts[*it] = upper_ends_ASC.UpperBoundRank(ranges[*it].second);
    upper_ends_ASC.Insert(ranges[*it].second);
  }
  Set<int, std::greater<int>> upper_ends_DESC;
  // Visit ranges in lower end ASC, upper end DESC order
  for (auto it = indexes.rbegin(); it != indexes.rend(); ++it) {
    contained_in_counts[*it] =
        upper_ends_DESC.UpperBoundRank(ranges[*it].second);
    upper_ends_DESC.Insert(ranges[*it].second);
  }
  for (auto it = contains_counts.begin(); it != contains_counts.end(); ++it) {
    if (it != contains_counts.begin()) {
      out << ' ';
    }
    out << *it;
  }
  out << '\n';
  for (auto it = contained_in_counts.begin(); it != contained_in_counts.end();
       ++it) {
    if (it != contained_in_counts.begin()) {
      out << ' ';
    }
    out << *it;
  }
  out << '\n';
}
