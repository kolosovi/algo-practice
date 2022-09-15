#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

TEST(SortColorsTest, 1) {
  Solution solution;
  std::vector<int> nums{0};
  std::vector<int> expected{0};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 2) {
  Solution solution;
  std::vector<int> nums{1};
  std::vector<int> expected{1};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 3) {
  Solution solution;
  std::vector<int> nums{2};
  std::vector<int> expected{2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 4) {
  Solution solution;
  std::vector<int> nums{2, 0, 2, 1, 1, 0};
  std::vector<int> expected{0, 0, 1, 1, 2, 2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 5) {
  Solution solution;
  std::vector<int> nums{2, 0, 1, 2};
  std::vector<int> expected{0, 1, 2, 2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 6) {
  Solution solution;
  std::vector<int> nums{0, 1, 2};
  std::vector<int> expected{0, 1, 2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 7) {
  Solution solution;
  std::vector<int> nums{0, 2, 1};
  std::vector<int> expected{0, 1, 2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 8) {
  Solution solution;
  std::vector<int> nums{1, 0, 2};
  std::vector<int> expected{0, 1, 2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 9) {
  Solution solution;
  std::vector<int> nums{1, 2, 0};
  std::vector<int> expected{0, 1, 2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 10) {
  Solution solution;
  std::vector<int> nums{2, 0, 1};
  std::vector<int> expected{0, 1, 2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, 11) {
  Solution solution;
  std::vector<int> nums{2, 1, 0};
  std::vector<int> expected{0, 1, 2};
  solution.sortColors(nums);
  EXPECT_EQ(nums, expected);
}
