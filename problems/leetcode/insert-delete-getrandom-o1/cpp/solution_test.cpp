#include <gtest/gtest.h>

#include "solution.hpp"

#include <random>

namespace {
static const int kSeed = 12345;
}

TEST(RandomizedSetTest, 1) {
  std::mt19937 rng(kSeed);
  RandomizedSet set(rng);
  EXPECT_TRUE(set.insert(1));
  EXPECT_FALSE(set.remove(2));
  EXPECT_TRUE(set.insert(2));
  EXPECT_EQ(set.getRandom(), 1);
  EXPECT_TRUE(set.remove(1));
  EXPECT_FALSE(set.insert(2));
  EXPECT_EQ(set.getRandom(), 2);
}
