#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

static const std::string::size_type kMaxVarNameLength = 5;
static const double kNotFound = -1.0;

struct EquationHasher {
    std::size_t operator()(const std::vector<std::string> &equation) const {
        std::string key(kMaxVarNameLength + kMaxVarNameLength, '0');
        for (std::string::size_type i = 0; i < equation[0].size(); i++) {
            key[i] = equation[0][i];
        }
        for (std::string::size_type i = 0; i < equation[1].size(); i++) {
            key[kMaxVarNameLength+i] = equation[1][i];
        }
        return string_hasher(key);
    }
    std::hash<std::string> string_hasher;
};

struct EquationEqualer {
    bool operator()(const std::vector<std::string> &lhs, const std::vector<std::string> &rhs) const {
        return lhs[0] == rhs[0] && lhs[1] == rhs[1];
    }
};

class Visitor {
public:
    Visitor(
        std::unordered_map<std::string, std::vector<std::string>> &children,
        std::unordered_map<std::vector<std::string>, double, EquationHasher, EquationEqualer> &divs,
        std::string target
    )
        : children_(children)
        , divs_(divs)
        , target_(target)
    {
    }

    double Visit(const std::string &var, double acc) {
        if (var == target_) {
            return acc;
        }
        for (const auto &child : children_[var]) {
            if (visited_.count(child) > 0) {
                continue;
            }
            visited_.insert(child);
            std::vector<std::string> equation{var, child};
            auto result = Visit(child, acc * divs_[equation]);
            if (result != kNotFound) {
                return result;
            }
        }
        return kNotFound;
    }

private:
    std::unordered_set<std::string> visited_;
    std::unordered_map<std::string, std::vector<std::string>> &children_;
    std::unordered_map<std::vector<std::string>, double, EquationHasher, EquationEqualer> &divs_;
    std::string target_;
};

class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        std::vector<double> result(queries.size(), kNotFound);
        std::unordered_set<std::string> vars;
        std::unordered_map<std::string, std::vector<std::string>> children;
        std::unordered_map<std::vector<std::string>, double, EquationHasher, EquationEqualer> divs;
        for (int i = 0; i < equations.size(); i++) {
            const auto &[var1, var2] = std::tie(equations[i][0], equations[i][1]);
            vars.insert(var1);
            vars.insert(var2);
            children[var1].emplace_back(var2);
            children[var2].emplace_back(var1);
            divs[equations[i]] = values[i];
            std::swap(equations[i][0], equations[i][1]);
            divs[equations[i]] = 1.0 / values[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            const auto &[var, target] = std::tie(queries[i][0], queries[i][1]);
            if (vars.count(var) == 0 || vars.count(target) == 0) {
                result[i] = kNotFound;
                continue;
            }
            Visitor visitor(children, divs, target);
            result[i] = visitor.Visit(var, 1.0);
        }
        return result;
    }
};
