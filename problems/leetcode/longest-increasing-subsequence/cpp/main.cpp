#include <vector>
#include <iostream>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> lenNums;
        std::vector<int> lens;
        int result = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            auto insertIdx = binarySearch(lenNums, nums[i]);
            if (insertIdx == lenNums.size()) {
                lenNums.resize(lenNums.size() + 1);
                lens.resize(lens.size() + 1);
            }
            int len = 1;
            if (insertIdx > 0) {
                len += lens[insertIdx - 1];
            }
            lenNums[insertIdx] = nums[i];
            lens[insertIdx] = len;
            result = std::max(result, len);
        }
        return result;
    }

private:
    int binarySearch(const std::vector<int> &nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            auto m = (l + r) / 2;
            if (nums[m] <= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    auto result = solution.lengthOfLIS(nums);
    std::cout << result << std::endl;
    return 0;
}
