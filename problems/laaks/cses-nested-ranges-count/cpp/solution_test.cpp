#include <gtest/gtest.h>

#include <testutil/file.hpp>

#include "solution.hpp"

#include <vector>

// TEST(TestSet, 1) {
//   // nums = [3, 7, 10, 12, 12, 15, 16, 17, 19, 20, 21, 23, 26, 28, 30, 35,
//   38,
//   // 39, 41, 47]
//   std::vector<int> numbers{3,  7,  10, 12, 12, 15, 16, 17, 19, 20,
//                            21, 23, 26, 28, 30, 35, 38, 39, 41, 47};
//   Set<int, std::less<int>> set;
//   EXPECT_EQ(0, set.Size());
//   EXPECT_EQ(0, set.UpperBoundRank(-100));
//   for (auto num : numbers) {
//     set.Insert(num);
//   }
//   EXPECT_EQ(20, set.Size());
//   EXPECT_EQ(20, set.UpperBoundRank(47));
//   EXPECT_EQ(19, set.UpperBoundRank(46));
//   EXPECT_EQ(9, set.UpperBoundRank(19));
//   EXPECT_EQ(8, set.UpperBoundRank(18));
//
//   set.Insert(19);
//   EXPECT_EQ(21, set.Size());
//   EXPECT_EQ(10, set.UpperBoundRank(19));
//   EXPECT_EQ(8, set.UpperBoundRank(18));
// }

TEST(TestCSESNestedRangesCount, 1) {
  EXPECT_EQ(
      "", testutil::FileBasedTest(Solve, __FILE__, "1.txt", "1_expected.txt"));
}
