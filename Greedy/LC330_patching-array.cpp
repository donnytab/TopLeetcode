/*
 *一个正整数 n 。从 [1, n] 区间内选取任意个数字补充到 nums 中，
 使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示
 请返回 满足上述要求的最少需要补充的数字个数 。

 1,2 -> [1,4)

1,2,4 -> [1,8)

1,2,4,8 -> [1,16]

1,2,4,8,16 -> [1,32)
 * */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];
                index++;
            } else {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
};
