#include <gtest/gtest.h>

#include "solution.hpp"

TEST(ImplementTrieTest, 1) {
  Trie trie;
  EXPECT_FALSE(trie.search("abracadabra"));
  EXPECT_FALSE(trie.startsWith("abracadabra"));
}

TEST(ImplementTrieTest, 2) {
  Trie trie;
  trie.insert("apple");
  EXPECT_TRUE(trie.search("apple"));
  EXPECT_FALSE(trie.search("app"));
  EXPECT_TRUE(trie.startsWith("app"));
  trie.insert("app");
  EXPECT_TRUE(trie.search("app"));
}

TEST(ImplementTrieTest, 3) {
  Trie trie;
  trie.insert("app");
  trie.insert("apple");
  trie.insert("beer");
  trie.insert("add");
  trie.insert("jam");
  trie.insert("rental");
  EXPECT_EQ(trie.search("apps"), false);
  EXPECT_EQ(trie.search("app"), true);
  EXPECT_EQ(trie.search("ad"), false);
  EXPECT_EQ(trie.search("applepie"), false);
  EXPECT_EQ(trie.search("rest"), false);
  EXPECT_EQ(trie.search("jan"), false);
  EXPECT_EQ(trie.search("rent"), false);
  EXPECT_EQ(trie.search("beer"), true);
  EXPECT_EQ(trie.search("jam"), true);
  EXPECT_EQ(trie.startsWith("apps"), false);
  EXPECT_EQ(trie.startsWith("app"), true);
  EXPECT_EQ(trie.startsWith("ad"), true);
  EXPECT_EQ(trie.startsWith("applepie"), false);
  EXPECT_EQ(trie.startsWith("rest"), false);
  EXPECT_EQ(trie.startsWith("jan"), false);
  EXPECT_EQ(trie.startsWith("rent"), true);
  EXPECT_EQ(trie.startsWith("beer"), true);
  EXPECT_EQ(trie.startsWith("jam"), true);
}
