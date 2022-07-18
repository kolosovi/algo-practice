#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(MaxProfitTest, 1) {
    Solution solution;
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    EXPECT_EQ(solution.maxProfit(prices), 5);
}
