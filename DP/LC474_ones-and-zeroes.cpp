// 经典的背包问题可以使用二维动态规划求解，两个维度分别是物品和容量。
// 这道题有两种容量，因此需要使用三维动态规划求解，三个维度分别是字符串、0 的容量和 1 的容量
class Solution {
    public:
        vector<int> getZerosOnes(string& str) {
            vector<int> zerosOnes(2);
            int length = str.length();
            for (int i = 0; i < length; i++) {
                zerosOnes[str[i] - '0']++;
            }
            return zerosOnes;
        }

        int findMaxForm(vector<string>& strs, int m, int n) {
            int length = strs.size();
            vector<vector<int>> dp(m + 1, vector<int>(n + 1));
            for (int i = 0; i < length; i++) {
                vector<int>&& zerosOnes = getZerosOnes(strs[i]);
                int zeros = zerosOnes[0], ones = zerosOnes[1];
                for (int j = m; j >= zeros; j--) {
                    for (int k = n; k >= ones; k--) {
                        dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                    }
                }
            }
            return dp[m][n];
        }
};
