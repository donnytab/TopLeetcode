// O(n^2)
// O(n^2)
// 对于一个子序列而言，如果它是回文子序列，并且长度大于 2，那么将它首尾的两个字符去除之后，它仍然是个回文子序列。因此可以用动态规划的方法计算给定字符串的最长回文子序列
// dp: 字符串 s 的下标范围 [i,j] 内的最长回文子序列的长度
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            vector<vector<int>> dp(n, vector<int>(n));
            for (int i = n - 1; i >= 0; i--) {
                dp[i][i] = 1;
                char c1 = s[i];
                for (int j = i + 1; j < n; j++) {
                    char c2 = s[j];
                    if (c1 == c2) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    } else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[0][n - 1];
        }
};
