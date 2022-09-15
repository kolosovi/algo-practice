#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(CoinChangeTest, 1) {
  Solution solution;
  std::vector<int> coins{2};
  EXPECT_EQ(solution.coinChange(coins, 3), -1);
}

TEST(CoinChangeTest, 2) {
  Solution solution;
  std::vector<int> coins{1};
  EXPECT_EQ(solution.coinChange(coins, 0), 0);
}

TEST(CoinChangeTest, 3) {
  Solution solution;
  std::vector<int> coins{1, 2, 5};
  EXPECT_EQ(solution.coinChange(coins, 11), 3);
}
