#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(PeakIndexInMountainArray, 1) {
  Solution solution;
  std::vector<int> input{0, 10, 5, 2};
  EXPECT_EQ(solution.peakIndexInMountainArray(input), 1);
}

TEST(PeakIndexInMountainArray, 2) {
  Solution solution;
  std::vector<int> input{0, 5, 10, 2};
  EXPECT_EQ(solution.peakIndexInMountainArray(input), 2);
}
