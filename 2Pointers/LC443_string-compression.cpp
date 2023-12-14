// 输入：chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// 输出：返回 4 ，输入数组的前 4 个字符应该是：["a","b","1","2"]。
// O(n)
// O(1)
class Solution {
    public:
        int compress(vector<char>& chars) {
            int n = chars.size();
            int write = 0, left = 0;
            for (int read = 0; read < n; read++) {
                if (read == n - 1 || chars[read] != chars[read + 1]) {
                    chars[write++] = chars[read];
                    int num = read - left + 1;
                    if (num > 1) {
                        int anchor = write;
                        while (num > 0) {
                            chars[write++] = num % 10 + '0';
                            num /= 10;
                        }
                        reverse(&chars[anchor], &chars[write]);
                    }
                    left = read + 1;
                }
            }
            return write;
        }
};
