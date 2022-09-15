#pragma once

#include <vector>
#include <string>
#include <cstdlib>

class Solution {
 public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::vector<int> stack;
    std::vector<std::string> operators{"+", "-", "*", "/"};
    for (const auto& token : tokens) {
      if (std::find(operators.begin(), operators.end(), token) !=
          operators.end()) {
        auto op2 = *stack.rbegin(), op1 = *(std::next(stack.rbegin()));
        stack.pop_back();
        stack.pop_back();
        int result = 0;
        if (token == "+") {
          result = op1 + op2;
        }
        if (token == "-") {
          result = op1 - op2;
        }
        if (token == "*") {
          result = op1 * op2;
        }
        if (token == "/") {
          result = op1 / op2;
        }
        stack.emplace_back(result);
      } else {
        stack.emplace_back(std::atoi(token.c_str()));
      }
    }
    return stack.front();
  }
};
