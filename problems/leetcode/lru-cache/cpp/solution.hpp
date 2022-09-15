#pragma once

#include <unordered_map>

struct Node {
  int key;
  int value;
  Node *next;
  Node *prev;
};

class List {
 public:
  ~List() {
    for (auto *cur = front_; cur != nullptr;) {
      auto *next_cur = cur->next;
      delete cur;
      cur = next_cur;
    }
  }

  Node *Append(int key, int value) {
    auto *node = new Node{key, value, nullptr, nullptr};
    if (back_ == nullptr) {
      front_ = node;
      back_ = node;
      return node;
    }
    back_->next = node;
    node->prev = back_;
    back_ = node;
    return node;
  }

  int PopFront() {
    int key = front_->key;
    if (front_->next == nullptr) {
      delete front_;
      front_ = nullptr;
      back_ = nullptr;
      return key;
    }
    auto *new_front = front_->next;
    delete front_;
    new_front->prev = nullptr;
    front_ = new_front;
    return key;
  }

  void MoveToBack(Node *node) {
    if (node->next == nullptr) {
      return;
    }
    node->next->prev = node->prev;
    if (node->prev == nullptr) {
      front_ = node->next;
    } else {
      node->prev->next = node->next;
    }
    back_->next = node;
    node->prev = back_;
    node->next = nullptr;
    back_ = node;
  }

 private:
  Node *front_;
  Node *back_;
};

class LRUCache {
 public:
  LRUCache(int capacity) : list_(), nodes_(), capacity_(capacity) {}

  int get(int key) {
    auto it = nodes_.find(key);
    if (it == nodes_.end()) {
      return -1;
    }
    list_.MoveToBack(it->second);
    return it->second->value;
  }

  void put(int key, int value) {
    auto it = nodes_.find(key);
    if (it != nodes_.end()) {
      it->second->value = value;
      list_.MoveToBack(it->second);
      return;
    }
    if (nodes_.size() == capacity_) {
      auto evicted_key = list_.PopFront();
      nodes_.erase(evicted_key);
    }
    nodes_[key] = list_.Append(key, value);
  }

 private:
  List list_;
  std::unordered_map<int, Node *> nodes_;
  int capacity_;
};
