#pragma once

#include <atomic>

class Spinlock {
 public:
  Spinlock();

  void lock();

  void unlock();

  bool try_lock();

 private:
  std::atomic<bool> is_locked_;
};
