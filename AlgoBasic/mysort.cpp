#include "mysort.hpp"

namespace std {
    void bubble_sort(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len - 1; ++i) {
            for (int j = 0; j < len - 1 - i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
}
