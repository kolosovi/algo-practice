#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(GasStationTest, 1) {
    Solution solution;
    std::vector<int> gas{1,2,3,4,5};
    std::vector<int> cost{3,4,5,1,2};
    EXPECT_EQ(solution.canCompleteCircuit(gas, cost), 3);
}
