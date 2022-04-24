#include <gtest/gtest.h>
#include <thread>
#include <vector>

#include "spinlock.hpp"

TEST(SpinlockLockTest, MutualExclusion) {
    Spinlock mutex;
    int counter = 0;
    int N = 1000;
    std::vector<std::thread> children;
    for (int i = 0; i < N; i++) {
        children.emplace_back([&mutex, &counter] {
            mutex.lock();
            if (counter == 0) {
                counter++;
            }
            mutex.unlock();
        });
    }
    for (auto & child : children) {
        child.join();
    }
    EXPECT_EQ(counter, 1);
}

TEST(SpinlockLockTest, TryLock) {
    Spinlock mutex;
    EXPECT_TRUE(mutex.try_lock());
    std::thread child([&mutex] {
        EXPECT_FALSE(mutex.try_lock());
    });
    child.join();
}

TEST(SpinlockLockTest, Unlock) {
    Spinlock mutex;
    mutex.lock();

    std::thread child1([&mutex] {
        EXPECT_FALSE(mutex.try_lock());
    });
    child1.join();

    mutex.unlock();

    std::thread child2([&mutex] {
        EXPECT_TRUE(mutex.try_lock());
    });
    child2.join();
}
