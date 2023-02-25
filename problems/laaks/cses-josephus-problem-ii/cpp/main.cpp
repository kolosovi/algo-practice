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

    bool isRed() const { return color_ == RED; }

    bool isBlack() const { return color_ == BLACK; }

    Node *parent_;
    Node *left_;
    Node *right_;
    K key_;
    int size_;
    Color color_;
  };

  Set() : cmp_(), nil_(new Node()), root_(nil_) {}

  ~Set() {}

  void Insert(K key) {
    Node *parent = nil_, *place = root_;
    while (place != nil_) {
      parent = place;
      parent->size_++;
      if (cmp_(key, place->key_)) {
        place = place->left_;
      } else if (cmp_(place->key_, key)) {
        place = place->right_;
      } else {
        return;
      }
    }
    auto *node = new Node(parent, nil_, nil_, key);
    if (parent == nil_) {
      root_ = node;
    } else if (cmp_(key, parent->key_)) {
      parent->left_ = node;
    } else {
      parent->right_ = node;
    }
    insertFixup(node);
  }

  Node *Select(int offset) {
    if (root_ == nil_ || offset >= Size() || offset < 0) {
      return nullptr;
    }
    int acc = 0;
    Node *cur = root_;
    while (acc + cur->left_->size_ != offset) {
      if (offset < acc + cur->left_->size_) {
        cur = cur->left_;
      } else {
        acc += cur->left_->size_ + 1;
        cur = cur->right_;
      }
    }
    return cur;
  }

  void Delete(Node *node) {
    Node *odd = nil_, *odd_parent = node;
    Color odd_parent_color = node->color_;
    if (node->right_ == nil_) {
      odd = node->left_;
      transplant(node, node->left_);
    } else if (node->left_ == nil_) {
      odd = node->right_;
      transplant(node, node->right_);
    } else {
      odd_parent = min(node->right_);
      odd_parent_color = odd_parent->color_;
      odd = odd_parent->right_;
      if (odd_parent != node->right_) {
        transplant(odd_parent, odd);
        odd_parent->right_ = node->right_;
        node->right_->parent_ = odd_parent;
      } else {
        odd->parent_ = odd_parent;
      }
      transplant(node, odd_parent);
      odd_parent->left_ = node->left_;
      node->left_->parent_ = odd_parent;
      odd_parent->color_ = node->color_;
      odd_parent->size_ = node->size_;
    }
    delete node;
    for (auto *parent = odd->parent_; parent != nil_;
         parent = parent->parent_) {
      parent->size_--;
    }
    if (odd_parent_color == BLACK) {
      deleteFixup(odd);
    }
  }

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

  void insertFixup(Node *node) {
    while (node->parent_->isRed()) {
      if (node->parent_ == node->parent_->parent_->left_) {
        auto *uncle = node->parent_->parent_->right_;
        if (uncle->isRed()) {
          node->parent_->color_ = BLACK;
          uncle->color_ = BLACK;
          node->parent_->parent_->color_ = RED;
          node = node->parent_->parent_;
          continue;
        }
        if (node == node->parent_->right_) {
          node = node->parent_;
          leftRotate(node);
        }
        rightRotate(node->parent_->parent_);
        node->parent_->color_ = BLACK;
        node->parent_->right_->color_ = RED;
        node = node->parent_;
      } else {
        auto *uncle = node->parent_->parent_->left_;
        if (uncle->isRed()) {
          node->parent_->color_ = BLACK;
          uncle->color_ = BLACK;
          node->parent_->parent_->color_ = RED;
          node = node->parent_->parent_;
          continue;
        }
        if (node == node->parent_->left_) {
          node = node->parent_;
          rightRotate(node);
        }
        leftRotate(node->parent_->parent_);
        node->parent_->color_ = BLACK;
        node->parent_->left_->color_ = RED;
        node = node->parent_;
      }
    }
    root_->color_ = BLACK;
  }

  void leftRotate(Node *node) {
    auto *replacement = node->right_;
    replacement->parent_ = node->parent_;
    if (node->parent_ == nil_) {
      root_ = replacement;
    } else if (node == node->parent_->left_) {
      node->parent_->left_ = replacement;
    } else {
      node->parent_->right_ = replacement;
    }
    node->right_ = replacement->left_;
    if (node->right_ != nil_) {
      node->right_->parent_ = node;
    }
    replacement->left_ = node;
    node->parent_ = replacement;
    replacement->size_ = node->size_;
    node->size_ = node->left_->size_ + node->right_->size_ + 1;
  }

  void rightRotate(Node *node) {
    auto *replacement = node->left_;
    replacement->parent_ = node->parent_;
    if (node->parent_ == nil_) {
      root_ = replacement;
    } else if (node == node->parent_->left_) {
      node->parent_->left_ = replacement;
    } else {
      node->parent_->right_ = replacement;
    }
    node->left_ = replacement->right_;
    if (node->left_ != nil_) {
      node->left_->parent_ = node;
    }
    replacement->right_ = node;
    node->parent_ = replacement;
    replacement->size_ = node->size_;
    node->size_ = node->left_->size_ + node->right_->size_ + 1;
  }

  void transplant(Node *from, Node *to) {
    to->parent_ = from->parent_;
    if (to->parent_ == nil_) {
      root_ = to;
    } else if (from == from->parent_->left_) {
      to->parent_->left_ = to;
    } else {
      to->parent_->right_ = to;
    }
  }

  Node *min(Node *node) {
    while (node->left_ != nil_) {
      node = node->left_;
    }
    return node;
  }

  void deleteFixup(Node *odd) {
    while (odd != root_ && odd->isBlack()) {
      if (odd == odd->parent_->left_) {
        auto *brother = odd->parent_->right_;
        if (brother->isRed()) {
          brother->color_ = BLACK;
          odd->parent_->color_ = RED;
          leftRotate(odd->parent_);
          brother = odd->parent_->right_;
        }
        if (brother->left_->isBlack() && brother->right_->isBlack()) {
          brother->color_ = RED;
          odd = odd->parent_;
          continue;
        }
        if (brother->right_->isBlack()) {
          brother->color_ = RED;
          brother->left_->color_ = BLACK;
          rightRotate(brother);
          brother = odd->parent_->right_;
        }
        brother->right_->color_ = BLACK;
        brother->color_ = odd->parent_->color_;
        odd->parent_->color_ = BLACK;
        leftRotate(odd->parent_);
        odd = root_;
      } else {
        auto *brother = odd->parent_->left_;
        if (brother->isRed()) {
          brother->color_ = BLACK;
          odd->parent_->color_ = RED;
          rightRotate(odd->parent_);
          brother = odd->parent_->left_;
        }
        if (brother->left_->isBlack() && brother->right_->isBlack()) {
          brother->color_ = RED;
          odd = odd->parent_;
          continue;
        }
        if (brother->left_->isBlack()) {
          brother->color_ = RED;
          brother->right_->color_ = BLACK;
          leftRotate(brother);
          brother = odd->parent_->left_;
        }
        brother->left_->color_ = BLACK;
        brother->color_ = odd->parent_->color_;
        odd->parent_->color_ = BLACK;
        rightRotate(odd->parent_);
        odd = root_;
      }
    }
    odd->color_ = BLACK;
  }
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
    if (set.Size() == 0) {
      break;
    }
    offset = (offset + k) % set.Size();
  }
  out << '\n';
}

int main() { Solve(std::cin, std::cout); }
