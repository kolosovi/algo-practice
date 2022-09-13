#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(TestJobScheduling, 1) {
    Solution solution;
    std::vector<int> start_time{1, 2, 3, 3};
    std::vector<int> end_time{3, 4, 5, 6};
    std::vector<int> profit{50, 10, 40, 70};
    int expected = 120;
    EXPECT_EQ(solution.jobScheduling(start_time, end_time, profit), expected);
}

TEST(TestJobScheduling, 2) {
    Solution solution;
    std::vector<int> start_time{1, 2, 3, 4, 6};
    std::vector<int> end_time{3, 5, 10, 6, 9};
    std::vector<int> profit{20, 20, 100, 70, 60};
    int expected = 150;
    EXPECT_EQ(solution.jobScheduling(start_time, end_time, profit), expected);
}

TEST(TestJobScheduling, 3) {
    Solution solution;
    std::vector<int> start_time{1, 1, 1};
    std::vector<int> end_time{2, 3, 4};
    std::vector<int> profit{5, 6, 4};
    int expected = 6;
    EXPECT_EQ(solution.jobScheduling(start_time, end_time, profit), expected);
}
