#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(CloneGraphTest, 1) {
    Solution solution;
    auto one = new Node(1);
    auto two = new Node(2);
    auto three = new Node(3);
    auto four = new Node(4);
    one->neighbors.insert(one->neighbors.end(), {two, four});
    two->neighbors.insert(two->neighbors.end(), {one, three});
    three->neighbors.insert(three->neighbors.end(), {two, four});
    four->neighbors.insert(four->neighbors.end(), {one, three});
    EXPECT_NE(solution.cloneGraph(one), nullptr);
}

TEST(CloneGraphTest, 2) {
    Solution solution;
    EXPECT_EQ(solution.cloneGraph(nullptr), nullptr);
}
