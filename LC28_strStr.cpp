/*
 *  KMP algorithm
 * */
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.length(), m = p.length();
        if (m == 0) return 0;

        // indexes start from 0
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');

        vector<int> next(m + 1);

        // init next array
        for (int i = 2, j = 0; i <= m; i++) {
            while (j > 0 && p[i] != p[j+1]) {
                j = next[j];
            }
            if (p[i]== p[j+1]) {
                j++;
            }
            next[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j > 0 && s[i] != p[j+1]) {
                j = next[j];
            }
            if (s[i] == p[j+1]) {
                j++;
            }
            if (j == m) {
                return i - m;
            }
        }
        return -1;
    }
};
