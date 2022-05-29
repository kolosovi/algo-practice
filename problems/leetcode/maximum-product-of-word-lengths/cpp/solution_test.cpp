#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>
#include <string>

TEST(MaximumProductOfWordLengthsTest, 1) {
    Solution solution;
    std::vector<std::string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    EXPECT_EQ(solution.maxProduct(words), 16);
}
