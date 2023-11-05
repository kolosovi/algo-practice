#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(CoinChangeII, 1) {
  Solution solution;
  std::vector<int> coins{1, 2, 5};
  EXPECT_EQ(4, solution.change(5, coins));
}

TEST(CoinChangeII, 2) {
  Solution solution;
  std::vector<int> coins{2};
  EXPECT_EQ(0, solution.change(3, coins));
}

TEST(CoinChangeII, 3) {
  Solution solution;
  std::vector<int> coins{10};
  EXPECT_EQ(1, solution.change(10, coins));
}
