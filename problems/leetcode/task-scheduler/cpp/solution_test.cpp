#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(LeastIntervalTest, 1) {
    Solution solution;
    std::vector<char> tasks{'A','A','A','B','B','B'};
    EXPECT_EQ(solution.leastInterval(tasks, 2), 8);
}

TEST(LeastIntervalTest, 2) {
    Solution solution;
    std::vector<char> tasks{'A','A','A','B','B','B'};
    EXPECT_EQ(solution.leastInterval(tasks, 0), 6);
}

TEST(LeastIntervalTest, 3) {
    Solution solution;
    std::vector<char> tasks{'A','A','A','A','A','A','B','C','D','E','F','G'};
    EXPECT_EQ(solution.leastInterval(tasks, 2), 16);
}

TEST(LeastIntervalTest, 4) {
    Solution solution;
    std::vector<char> tasks{'A','A','A','B','B','B','C','C','C','D','D','E'};
    EXPECT_EQ(solution.leastInterval(tasks, 2), 12);
}
