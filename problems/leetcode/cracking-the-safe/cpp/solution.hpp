#pragma once

#include <string>
#include <vector>
#include <unordered_set>

struct Visitor {
    bool Visit(std::string node) {
        path.emplace_back(node);
        visited.emplace(node);
        if (visited.size() == max_nodes) {
            return true;
        }
        std::string next_node(node);
        for (int i = 0; i < node.size() - 1; i++) {
            next_node[i] = node[i+1];
        }
        for (auto digit : digits) {
            next_node.back() = digit;
            if (visited.count(next_node)) {
                continue;
            }
            if (Visit(next_node)) {
                return true;
            }
        }
        path.pop_back();
        visited.erase(node);
        return false;
    }

    std::vector<std::string> path;
    std::unordered_set<std::string> visited;
    std::vector<char> digits;
    int max_nodes;
};

class Solution {
public:
    string crackSafe(int n, int k) {
        int max_nodes = 1;
        for (int i = 0; i < n; i++) {
            max_nodes *= k;
        }
        std::vector<char> digits(k, '0');
        for (int i = 1; i < k; i++) {
            digits[i] = digits[i-1] + 1;
        }
        Visitor visitor{{}, {}, digits, max_nodes};
        std::string node(n, '0');
        visitor.Visit(node);
        std::string result(n + max_nodes - 1, '0');
        int j = 0;
        for (int i = 0; i < visitor.path.size(); i++) {
            if (i > 0) {
                result[j++] = visitor.path[i].back();
                continue;
            }
            for (auto ch : visitor.path[i]) {
                result[j++] = ch;
            }
        }
        return result;
    }
};
