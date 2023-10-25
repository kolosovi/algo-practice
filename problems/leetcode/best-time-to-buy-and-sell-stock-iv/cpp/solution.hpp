#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

/*
 * How can I tell it's DP?
 *
 * 1. it's an optimization problem
 * 2. buying stock at day i and selling it at day j > i prevents me from buying
 * it at day k, i < k <= j
 *
 * but recall the definition of dp:
 * - overlapping subproblems
 * - optimal substructure
 *
 * Let's think of a DP solution
 *
 *                                                                                 i
 * 1. state: current day and # of used ops (each purchase & sale is an op)
 * 2. base cases. If i == len(prices), I cannot make any profit so the answer is
 * 0. If used ops >= double k, I cannot buy or sell anymore so the answer is 0.
 * Also if i == len(prices) - 1 && SELL, I MUST sell, so I return prices[i]. If
 * i == len(prices) - 1 && BUY, i CANNOT buy, so the answer is just 0.
 * 3. recurrence relation.
 *
 * Say I'm at day i with j purchases & k sales
 * If SELL: I cannot buy, I can only sell. I might sell now or I might sell
 * later, so it's max{ dp(i+1, BUY) + prices[i], dp(i+1, SELL) } If BUY: I
 * cannot sell, I can only buy. I might buy now or I might buy later, so it's
 *    max{ dp(i+1, SELL) - prices[i], dp(i+1, BUY) }
 */

static const int kBuy = -1;
static const int kSell = 1;

class Solution {
 public:
  int maxProfit(int k, std::vector<int>& prices) {
    this->k2x = 2 * k;
    this->prices = prices;
    mem.clear();
    return dp(0, 0);
  }

 private:
  int k2x;
  std::vector<int> prices;
  std::unordered_map<int, std::unordered_map<int, int>> mem;

  int dp(int i, int used_ops) {
    if (i == prices.size() || used_ops == k2x) {
      return 0;
    }
    auto& mem_used_ops = mem[i];
    auto it = mem_used_ops.find(used_ops);
    if (it == mem_used_ops.end()) {
      int op = used_ops % 2 == 0 ? kBuy : kSell;
      mem_used_ops[used_ops] = std::max(
          dp(i + 1, used_ops + 1) + op * prices[i], dp(i + 1, used_ops));
    }
    return mem_used_ops[used_ops];
  }
};
