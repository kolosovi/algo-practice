#pragma once

#include <vector>
#include <unordered_map>
#include <random>

class RandomizedSet {
public:
    RandomizedSet() : rng_(std::random_device{}()){
    }

    RandomizedSet(std::mt19937 rng) : rng_(rng){
    }

    bool insert(int val) {
        if (value_locs_.count(val) > 0) {
            return false;
        }
        values_.emplace_back(val);
        value_locs_[val] = values_.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (value_locs_.count(val) == 0) {
            return false;
        }
        auto old_loc = value_locs_[val];
        std::swap(values_[old_loc], values_.back());
        value_locs_[values_[old_loc]] = old_loc;
        value_locs_.erase(val);
        values_.pop_back();
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, values_.size()-1);
        int loc = dist(rng_);
        return values_[loc];
    }

private:
    std::vector<int> values_;
    std::unordered_map<int, int> value_locs_;
    std::mt19937 rng_;
};
