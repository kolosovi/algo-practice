#pragma once

#include <vector>

/*
1. state variables: index of coin and amount to do. Oooh, it's a neat idea,
because I use up all the coins of some kind before using some other kind of
coin. Perfect!
2. transition: I can use coin & this will give me dp(i, amount - coin_i) ways. I
can skip the coin & not use it, this will give me dp(i + 1, amount) ways.
3. base cases: amount < 0? 0. Amount = 0? 1.
*/

static constexpr int kNone = -1;

class Solution {
 public:
  int change(int amount, std::vector<int> &coins) {
    this->coins = coins;
    mem.resize(coins.size());
    for (auto &memrow : mem) {
      memrow.resize(amount + 1);
      for (auto &memcell : memrow) {
        memcell = kNone;
      }
    }
    return dp(0, amount);
  }

 private:
  std::vector<int> coins;
  std::vector<std::vector<int>> mem;

  int dp(int i, int amount) {
    if (amount < 0) {
      return 0;
    }
    if (amount == 0) {
      return 1;
    }
    if (i == coins.size()) {
      return 0;
    }
    if (mem[i][amount] == kNone) {
      mem[i][amount] = dp(i, amount - coins[i]) + dp(i + 1, amount);
    }
    return mem[i][amount];
  }
};
