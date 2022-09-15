#include "spinlock.hpp"

#include <atomic>

Spinlock::Spinlock() : is_locked_(false) {}

void Spinlock::lock() {
  while (is_locked_.exchange(true)) {
  }
}

void Spinlock::unlock() { is_locked_.store(false); }

bool Spinlock::try_lock() {
  bool expected = false;
  return is_locked_.compare_exchange_strong(expected, true);
}
