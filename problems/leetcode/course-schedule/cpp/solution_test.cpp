#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(CanFinishTest, 1) {
  Solution solution;
  std::vector<std::vector<int>> prerequisites{{1, 0}};
  int num_courses = 2;
  EXPECT_TRUE(solution.canFinish(num_courses, prerequisites));
}

TEST(CanFinishTest, 2) {
  Solution solution;
  std::vector<std::vector<int>> prerequisites{{1, 0}, {0, 1}};
  int num_courses = 2;
  EXPECT_FALSE(solution.canFinish(num_courses, prerequisites));
}
