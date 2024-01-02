// 输入：nums = [1,5,2]
// 输出：false
// 解释：一开始，玩家 1 可以从 1 和 2 中进行选择。
// 如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。 
// 所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
// 因此，玩家 1 永远不会成为赢家，返回 false 。
class Solution {
    public:
        bool PredictTheWinner(vector<int>& nums) {
            int length = nums.size();
            auto dp = vector<int>(length);
            for (int i = 0; i < length; i++) {
                dp[i] = nums[i];
            }
            for (int i = length - 2; i >= 0; i--) {
                for (int j = i + 1; j < length; j++) {
                    dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
                }
            }
            return dp[length - 1] >= 0;
        }
};
