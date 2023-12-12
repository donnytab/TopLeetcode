// 等差数列求和 K*(K+1)/2 = N
// https://leetcode.cn/problems/arranging-coins/solutions/1038396/pai-lie-ying-bi-by-leetcode-solution-w52c/
//

class Solution {
    public:
    int arrangeCoins(int n) {
            return (int) ((sqrt((long long) 8 * n + 1) - 1) / 2);
        }
};
