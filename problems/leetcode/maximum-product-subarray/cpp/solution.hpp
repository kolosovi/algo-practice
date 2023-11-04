#pragma once

#include <vector>
#include <algorithm>

/*
1. an optimization problem
2. future decisions depend on earlier decisions. E.g. if I maintain two pointers
and encounter a negative number & decide to move the left pointer past it, I
might lose the opportunity to gather a larger product.

But what I care about is optimal substructure, i.e. can I solve the problem by
combining solutions to subproblems.

1. state variables.
Maybe something like: current index? So answer is dp(0) -> but this doesn't make
sense because I must somehow combine solutions.

Another possibility is to reformulate the problem & say that I must find the
largest product formed by subarrays starting at i. In this case, the answer is
going to be max_i(dp(i)).

2. transition function

Say I start with index i, what are my options then?
- I can include only the ith number in the product
- I can combine it with the answer for i+1

3. base cases

base case: n=1, in this case it's just nums_0. Or maybe even n=0 and product =
1, but this is actually undefined.

0   1   2   3
2  -3  -2   4

dp(3): 4
dp(2): -2
dp(1): 6
dp(0): 12

But it actually should be 48, i.e. the best answer is given by just multiplying
everything. So my transition function doesn't work.

Hmmm..

Say I have R sums, I just go from right to left & compute right products. R_i is
the product of numbers from ith to N-1 inclusive, so R_(N-1) is just the last
number. R_N is 1.

I can go from right to left & for each i pick j: i < j <= N && R_i / R_j =
max_j(R_i / R_j).

R_i is positive: the smallest positive R_j or the smallest negative R_j
R_i is negative: the largest negative R_j or the largest positive R_j

So basically I go for
- smallest positive
- smallest negative
- largest negative
- largest positive

These numbers reset whenever I go through zero.
*/

static constexpr int kNone = -200001;
class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    int max = kNone;
    int min_pos = kNone, min_neg = kNone, max_neg = kNone, max_pos = kNone;
    int lproduct = 1;
    for (auto num : nums) {
      lproduct *= num;
      int ans = std::max(num, lproduct);
      if (lproduct > 0) {
        if (min_pos != kNone) {
          ans = std::max(ans, lproduct / min_pos);
        }
        if (min_neg != kNone) {
          ans = std::max(ans, lproduct / min_neg);
        }
      }
      if (lproduct < 0) {
        if (max_pos != kNone) {
          ans = std::max(ans, lproduct / max_pos);
        }
        if (max_neg != kNone) {
          ans = std::max(ans, lproduct / max_neg);
        }
      }
      if (lproduct > 0) {
        if (min_pos == kNone || lproduct < min_pos) {
          min_pos = lproduct;
        }
        if (max_pos == kNone || lproduct > max_pos) {
          max_pos = lproduct;
        }
      }
      if (lproduct < 0) {
        if (min_neg == kNone || lproduct < min_neg) {
          min_neg = lproduct;
        }
        if (max_neg == kNone || lproduct > max_neg) {
          max_neg = lproduct;
        }
      }
      if (lproduct == 0) {
        lproduct = 1;
        min_neg = kNone, max_neg = kNone, min_pos = kNone, max_pos = kNone;
      }
      max = std::max(max, ans);
    }
    return max;
  }
};
