// (1) 从字符串 s 的末尾开始往前取出字符构建新的字符串 ans。每次取出字符时首先判断该字符是否为破折号，如果为破折号则跳过；否则将当前的字符计数 cnt 加 1，同时检查如果当前字符为小写字母则将其转化为大写字母，将当前字符加入到字符串 ans 的末尾
// (2) 对字符进行计数时，每隔 k 个字符就在字符串 ans 中添加一个破折号。特殊情况需要处理，字符串 ans 的最后一个字符为破折号则将其去掉。
// (3) 反转字符串 ans
class Solution {
    public:
        string licenseKeyFormatting(string s, int k) {
            string ans;
            int cnt = 0;

            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] != '-') {
                    ans.push_back(toupper(s[i]));
                    cnt++;
                    if (cnt % k == 0) {
                        ans.push_back('-');
                    }
                }
            }
            if (ans.size() > 0 && ans.back() == '-') {
                ans.pop_back();
            }
            reverse(ans.begin(), ans.end());

            return ans;
        }
};
