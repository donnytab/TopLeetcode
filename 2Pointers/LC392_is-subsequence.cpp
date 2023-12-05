// O(n)
// O(1)
class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int n = s.length(), m = t.length();
            int i = 0, j = 0;
            while (i < n && j < m) {
                if (s[i] == t[j]) {
                    i++;
                }
                j++;
            }
            return i == n;
        }
};



// when the size of s is huge number (JAVA solution)
/*
   class Solution {
   public boolean isSubsequence(String s, String t) {

   // 预处理
   t = " " + t; // 开头加一个空字符作为匹配入口
   int n = t.length();
   int[][] dp = new int[n][26]; // 记录每个位置的下一个ch的位置
   for (char ch = 0; ch < 26; ch++) {
   int p = -1;
   for (int i = n - 1; i >= 0; i--) { // 从后往前记录dp
   dp[i][ch] = p;
   if (t.charAt(i) == ch + 'a') p = i;
   }
   }

    // 匹配
    int i = 0;
    for (char ch : s.toCharArray()) { // 跳跃遍历
        i = dp[i][ch - 'a'];
        if (i == -1) return false;
    }
    return true;
    }
    }
 * */
