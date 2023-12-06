// O(1)
// O(1)
// brute force
class Solution {
    public:
        vector<string> readBinaryWatch(int num) {
            vector<string> res;
            //直接遍历  0:00 -> 12:00   每个时间有多少1
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 60; j++) {
                    if (count1(i) + count1(j) == num) {
                        res.push_back(to_string(i)+":"+
                                (j < 10 ? "0"+to_string(j) : to_string(j)));
                    }
                }
            }
            return res;
        }
        //计算二进制中1的个数
        int count1(int n) {
            int res = 0;
            while (n != 0) {
                n = n & (n - 1);
                res++;
            }
            return res;
        }
};
