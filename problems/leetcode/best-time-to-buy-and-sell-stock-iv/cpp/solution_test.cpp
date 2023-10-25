#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(BestTimeToBuyAndSellStockIV, 1) {
  Solution solution;
  std::vector<int> prices{2, 4, 1};
  EXPECT_EQ(2, solution.maxProfit(2, prices));
}

TEST(BestTimeToBuyAndSellStockIV, 2) {
  Solution solution;
  std::vector<int> prices{3, 2, 6, 5, 0, 3};
  EXPECT_EQ(7, solution.maxProfit(2, prices));
}
