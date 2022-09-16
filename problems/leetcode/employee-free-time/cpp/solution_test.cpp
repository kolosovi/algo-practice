#include <gtest/gtest.h>

#include "solution.hpp"

#include <vector>

struct IntervalEq {
  bool operator()(const Interval &lhs, const Interval &rhs) const {
    return std::tie(lhs.start, lhs.end) == std::tie(rhs.start, rhs.end);
  }
};

TEST(EmployeeFreeTimeTest, 1) {
  Solution solution;
  std::vector<std::vector<Interval>> schedule{
      {{1, 2}, {5, 6}}, {{1, 3}}, {{4, 10}}};
  std::vector<Interval> expected{{3, 4}};
  auto actual = solution.employeeFreeTime(schedule);
  IntervalEq cmp;
  EXPECT_EQ(actual.size(), expected.size());
  for (int i = 0; i < actual.size(); i++) {
    EXPECT_TRUE(cmp(actual[i], expected[i]));
  }
}

TEST(EmployeeFreeTimeTest, 2) {
  Solution solution;
  std::vector<std::vector<Interval>> schedule{
      {{1, 3}, {6, 7}}, {{2, 4}}, {{2, 5}, {9, 12}}};
  std::vector<Interval> expected{{5, 6}, {7, 9}};
  auto actual = solution.employeeFreeTime(schedule);
  IntervalEq cmp;
  EXPECT_EQ(actual.size(), expected.size());
  for (int i = 0; i < actual.size(); i++) {
    EXPECT_TRUE(cmp(actual[i], expected[i]));
  }
}

TEST(EmployeeFreeTimeTest, 3) {
  Solution solution;
  std::vector<std::vector<Interval>> schedule{{{43, 76}, {86, 91}},
                                              {{17, 20}, {29, 30}}};
  std::vector<Interval> expected{{20, 29}, {30, 43}, {76, 86}};
  auto actual = solution.employeeFreeTime(schedule);
  IntervalEq cmp;
  EXPECT_EQ(actual.size(), expected.size());
  for (int i = 0; i < actual.size(); i++) {
    EXPECT_TRUE(cmp(actual[i], expected[i]));
  }
}
