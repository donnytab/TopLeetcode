class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

/*
  n & (n - 1)  可以直接将 n 二进制表示的最低位 1 移除
  n & (-n)     可以直接获取 n 二进制表示的最低位的 1

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};
*/
