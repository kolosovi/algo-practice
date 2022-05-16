#pragma once

#include <vector>
#include <algorithm>

struct Greater {
    bool operator()(const int &lhs, const int &rhs) {
        return lhs > rhs;
    }
};

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        Greater comp;
        std::vector<int> heap;
        for (auto num : nums) {
            heap.push_back(num);
            std::push_heap(heap.begin(), heap.end(), comp);
            if (heap.size() > k) {
                std::pop_heap(heap.begin(), heap.end(), comp);
                heap.pop_back();
            }
        }
        return heap[0];
    }
};
