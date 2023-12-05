

// 1. simulation
class Solution {
    public:
        int lastRemaining(int n) {
            int head = 1;
            int step = 1;
            bool left = true;
            int n = n

                while (n > 1) {
                    //从左边开始移除 or（从右边开始移除，数列总数为奇数）
                    if (left || n % 2 != 0) {
                        head += step;
                    }
                    step <<= 1; //步长 * 2
                    n >>= 1;  //总数 / 2
                    left = !left; //取反移除方向
                }

            return head;
        }
};

// 2. Josephus ring  约瑟夫环
class Solution {
    public:
    int lastRemaining(int n) {
            return n==1 ? 1 : 2*(n/2+1-lastRemaining(n/2));
        }
};
