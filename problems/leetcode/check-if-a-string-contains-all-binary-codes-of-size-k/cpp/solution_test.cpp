#include <gtest/gtest.h>

#include "solution.hpp"

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeKTest, 1) {
    Solution solution;
    EXPECT_TRUE(solution.hasAllCodes("00110110", 2));
}
