// O(n)
// O(1)
// 输入: nums = [4,3,2,6]
// 输出: 26
// 解释:
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
// 所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
class Solution {
    public:
        int maxRotateFunction(vector<int>& nums) {
            int f = 0, n = nums.size();
            int numSum = accumulate(nums.begin(), nums.end(), 0);
            for (int i = 0; i < n; i++) {
                f += i * nums[i];
            }
            int res = f;
            for (int i = n - 1; i > 0; i--) {
                f += numSum - n * nums[i];
                res = max(res, f);
            }
            return res;
        }
};
