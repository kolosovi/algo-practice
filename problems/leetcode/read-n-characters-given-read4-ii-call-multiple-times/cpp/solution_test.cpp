#include <gtest/gtest.h>

#include "solution.hpp"

TEST(ReadNCharactersGivenRead4IICallMultipleTimes, 1) {
  Solution solution;
  EXPECT_EQ(solution.read(nullptr, 100500), 0);
}
