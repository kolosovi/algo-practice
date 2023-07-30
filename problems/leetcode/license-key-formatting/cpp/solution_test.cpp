#include <gtest/gtest.h>

#include "solution.hpp"

TEST(LeetcodeLicenseKeyFormattingTest, 1) {
  Solution solution;
  EXPECT_EQ(solution.licenseKeyFormatting("5F3Z-2e-9-w", 4), "5F3Z-2E9W");
}

TEST(LeetcodeLicenseKeyFormattingTest, 2) {
  Solution solution;
  EXPECT_EQ(solution.licenseKeyFormatting("2-5g-3-J", 2), "2-5G-3J");
}
