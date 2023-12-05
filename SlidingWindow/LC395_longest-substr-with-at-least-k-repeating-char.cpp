// O(26)
// O(26)
// 输入：s = "ababbc", k = 2
// 输出：5
// 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
//
class Solution {
    public:
        int longestSubstring(string s, int k) {
            int ret = 0;
            int n = s.length();
            for (int t = 1; t <= 26; t++) {
                int l = 0, r = 0;
                vector<int> cnt(26, 0);
                int tot = 0;
                int less = 0;
                while (r < n) {
                    cnt[s[r] - 'a']++;
                    if (cnt[s[r] - 'a'] == 1) {
                        tot++;
                        less++;
                    }
                    if (cnt[s[r] - 'a'] == k) {
                        less--;
                    }

                    while (tot > t) {
                        cnt[s[l] - 'a']--;
                        if (cnt[s[l] - 'a'] == k - 1) {
                            less++;
                        }
                        if (cnt[s[l] - 'a'] == 0) {
                            tot--;
                            less--;
                        }
                        l++;
                    }
                    if (less == 0) {
                        ret = max(ret, r - l + 1);
                    }
                    r++;
                }
            }
            return ret;
        }
};
