// 输入：n = "13"
// 输出："3"
// 解释：13 的 3 进制是 111。
// O(logn^2)
// O(1)
class Solution {
    public:
        string smallestGoodBase(string n) {
            long num = stol(n);
            // 枚举 k进制 中 1 的个数，最多为 二进制 时的位数
            for (int i = (int)(log(num) / log(2) + 1); i > 2; --i) {
                // k^0 + k^1 + …… + k^(i-1) = n -- 通过二分法计算 k
                long left = 2, right = num - 1;
                while (left <= right) {
                    long mid = left + (right - left) / 2;
                    // MaxVal 用于反向溢出判断，一旦溢出，说明比num大，设为num+1即可
                    long s = 0, MaxVal = num / mid + 1;
                    for (int j = 0; j < i; ++j) {
                        if (s < MaxVal)
                            s = s * mid + 1;
                        else {
                            s = num + 1;
                            break;
                        }
                    }
                    if (s == num)
                        return to_string(mid);
                    else if (s > num)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
            }
            return to_string(num - 1);
        }
};
