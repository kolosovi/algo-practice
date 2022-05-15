#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>
#include <string>

TEST(FindMissingRangesTest, 1) {
    Solution solution;
    std::vector<int> nums;
    int lower = 1, upper = 1;
    std::vector<std::string> expected{"1"};
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}

TEST(FindMissingRangesTest, 2) {
    Solution solution;
    std::vector<int> nums;
    int lower = 1, upper = 10;
    std::vector<std::string> expected{"1->10"};
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}

TEST(FindMissingRangesTest, 3) {
    Solution solution;
    std::vector<int> nums{1,2,3,4,5};
    int lower = 1, upper = 5;
    std::vector<std::string> expected;
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}

TEST(FindMissingRangesTest, 4) {
    Solution solution;
    std::vector<int> nums{2,3,4,5};
    int lower = 1, upper = 5;
    std::vector<std::string> expected{"1"};
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}

TEST(FindMissingRangesTest, 5) {
    Solution solution;
    std::vector<int> nums{3,4,5};
    int lower = 1, upper = 5;
    std::vector<std::string> expected{"1->2"};
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}

TEST(FindMissingRangesTest, 6) {
    Solution solution;
    std::vector<int> nums{1,2,3,4};
    int lower = 1, upper = 5;
    std::vector<std::string> expected{"5"};
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}

TEST(FindMissingRangesTest, 7) {
    Solution solution;
    std::vector<int> nums{1,2,3};
    int lower = 1, upper = 5;
    std::vector<std::string> expected{"4->5"};
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}

TEST(FindMissingRangesTest, 8) {
    Solution solution;
    std::vector<int> nums{1,3,4,5};
    int lower = 1, upper = 5;
    std::vector<std::string> expected{"2"};
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}

TEST(FindMissingRangesTest, 9) {
    Solution solution;
    std::vector<int> nums{1,4,5};
    int lower = 1, upper = 5;
    std::vector<std::string> expected{"2->3"};
    EXPECT_EQ(solution.findMissingRanges(nums, lower, upper), expected);
}
