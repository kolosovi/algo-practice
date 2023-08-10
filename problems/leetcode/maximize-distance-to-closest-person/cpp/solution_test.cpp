#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(MaximizeDistanceToClosestPerson, 1) {
  Solution solution;
  std::vector<int> seats{1, 0, 0, 0, 1, 0, 1};
  EXPECT_EQ(solution.maxDistToClosest(seats), 2);
}
