class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};
// 16进制的mask=(10101010101010101010101010101010) = aaaaaaaa
