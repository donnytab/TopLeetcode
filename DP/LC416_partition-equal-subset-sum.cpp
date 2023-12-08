// O(n^target)
// O(target)
// 转化为0-1背包问题
// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            if (n < 2) {
                return false;
            }
            int sum = 0, maxNum = 0;
            for (auto& num : nums) {
                sum += num;
                maxNum = max(maxNum, num);
            }
            if (sum & 1) {
                return false;
            }
            int target = sum / 2;
            if (maxNum > target) {
                return false;
            }
            vector<int> dp(target + 1, 0);
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                int num = nums[i];
                for (int j = target; j >= num; --j) {
                    dp[j] |= dp[j - num];
                }
            }
            return dp[target];
        }
};
