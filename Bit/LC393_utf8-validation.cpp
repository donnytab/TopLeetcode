// UTF-8 中的一个字符可能的长度为 1 到 4 字节,因此只判断编码中的前1-5bits value.
//
// 简单的来说可以分为5种情况:
//
// 首字节（4种情况）：0xxxxxxx, 110xxxxx, 1110xxxx, 11110xxx, 后面字节（1种情况）：10xxxxxx
//
// 只需要对这5种情况分别进行讨论我们便知道所给的编码是否合法.
//
// 判断时采用右移法
class Solution {
    public:
        bool validUtf8(vector<int>& data) {
            int bitIndex = 0;//用于判断data首字节后一共有几个字节
            for(const int num : data) {
                if(bitIndex == 0) {
                    if((num >> 5) == 0b110) bitIndex = 1;
                    else if((num >> 4) == 0b1110) bitIndex = 2;
                    else if((num >> 3) == 0b11110) bitIndex = 3;
                    else if(num >> 7) return false;
                } else {
                    if((num >> 6) != 0b10) return false;
                    --bitIndex;
                }
            }
            return bitIndex == 0;
        }
};


// official answer
class Solution {
    public:
        static const int MASK1 = 1 << 7;
        static const int MASK2 = (1 << 7) + (1 << 6);

        bool isValid(int num) {
            return (num & MASK2) == MASK1;
        }

        int getBytes(int num) {
            if ((num & MASK1) == 0) {
                return 1;
            }
            int n = 0;
            int mask = MASK1;
            while ((num & mask) != 0) {
                n++;
                if (n > 4) {
                    return -1;
                }
                mask >>= 1;
            }
            return n >= 2 ? n : -1;
        }

        bool validUtf8(vector<int>& data) {
            int m = data.size();
            int index = 0;
            while (index < m) {
                int num = data[index];
                int n = getBytes(num);
                if (n < 0 || index + n > m) {
                    return false;
                }
                for (int i = 1; i < n; i++) {
                    if (!isValid(data[index + i])) {
                        return false;
                    }
                }
                index += n;
            }
            return true;
        }
};
