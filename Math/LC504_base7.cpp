// 输入: num = 100
// 输出: "202"
// 七进制数

class Solution {
    public:
        string convertToBase7(int num) {
            if (num == 0) {
                return "0";
            }
            bool negative = num < 0;
            num = abs(num);
            string digits;
            while (num > 0) {
                digits.push_back(num % 7 + '0');
                num /= 7;
            }
            if (negative) {
                digits.push_back('-');
            }
            reverse(digits.begin(), digits.end());
            return digits;
        }
};
