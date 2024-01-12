// 输入：amount = 5, coins = [1, 2, 5]
// 输出：4
// 解释：有四种方式可以凑成总金额：
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// 每个元素可以选取多次，且不考虑选取元素的顺序
//

class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            vector<int> dp(amount + 1);
            dp[0] = 1;
            for (int& coin : coins) {
                for (int i = coin; i <= amount; i++) {
                    dp[i] += dp[i - coin];
                }
            }
            return dp[amount];
        }
};
