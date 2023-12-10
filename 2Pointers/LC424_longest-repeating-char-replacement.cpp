// O(n)
// O(26)
// 输入：s = "AABABBA", k = 1
//输出：4
//解释：
//将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
//子串 "BBBB" 有最长重复字母, 答案为 4。
class Solution {
  public:
    int characterReplacement(string s, int k) {
      vector<int> num(26);
      int n = s.length();
      int maxn = 0;
      int left = 0, right = 0;
      while (right < n) {
        num[s[right] - 'A']++;
        maxn = max(maxn, num[s[right] - 'A']);
        if (right - left + 1 - maxn > k) {
          num[s[left] - 'A']--;
          left++;
        }
        right++;
      }
      return right - left;
    }
};
