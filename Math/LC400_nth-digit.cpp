// O(logn)
// O(1)
// 输入：n = 11
// 输出：0
// 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
class Solution {
    public:
        int findNthDigit(int n) {
            int d = 1, count = 9;
            while (n > (long) d * count) {
                n -= d * count;
                d++;
                count *= 10;
            }
            int index = n - 1;
            int start = (int) pow(10, d - 1);
            int num = start + index / d;
            int digitIndex = index % d;
            int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10;
            return digit;
        }
};
