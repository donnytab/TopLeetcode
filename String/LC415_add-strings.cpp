class Solution {
    public:
        string addStrings(string num1, string num2) {
            int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
            string ans = "";
            while (i >= 0 || j >= 0 || carry != 0) {
                int x = i >= 0 ? num1[i] - '0' : 0;
                int y = j >= 0 ? num2[j] - '0' : 0;
                int result = x + y + carry;
                ans.push_back('0' + result % 10);
                carry = result / 10;
                --i;
                --j;
            }
            // 计算完以后的答案需要翻转过来
            reverse(ans.begin(), ans.end());
            return ans;
        }
};
