#include <gtest/gtest.h>

#include "solution.hpp"

#include <string>
#include <vector>

TEST(SubdomainVisitsTest, 1) {
    Solution solution;
    std::vector<std::string> input{"9001 discuss.leetcode.com"};
    std::vector<std::string> expected{"9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"};
    auto actual = solution.subdomainVisits(input);
    std::sort(expected.begin(), expected.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(expected, actual);
}
