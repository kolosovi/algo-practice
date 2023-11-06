#pragma once

#include <algorithm>
#include <vector>

/*
basic idea: dp(i) is the maximum profit I can achieve when selling on the ith
day. base cases: dp(0) is just 0 (no profit can be achieved).

transition: say I'm looking at day i. It seems that there are two options:
- it's profitable to buy on the same day as i-1, so profit from selling on the
ith day is dp(i-1) + prices_i - prices_(i-1)
- it's profitable to buy on the previous (i-1th) day, so profit is prices_i -
prices_(i-1)
*/
class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int max = 0, current = 0;
    for (int i = 1; i < prices.size(); i++) {
      current = std::max(current + prices[i] - prices[i - 1],
                         prices[i] - prices[i - 1]);
      max = std::max(max, current);
    }
    return max;
  }
};

class SolutionOld {
 public:
  int maxProfit(std::vector<int>& prices) {
    int max = 0, min = 10001;
    for (auto price : prices) {
      min = std::min(min, price);
      max = std::max(max, price - min);
    }
    return max;
  }
};
