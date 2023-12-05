// O(n)
// O(1)
//
// 输入：n = 13
// 输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
class Solution {
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ret(n);
        int iNumber = 1;
        for (int i = 0; i < n; ++i)
        {
            ret[i] = iNumber;
            if (iNumber * 10 <= n)
            {
                iNumber *= 10;
            }
            else
            {
                while (iNumber % 10 == 9 || iNumber + 1 > n)
                {
                    iNumber /= 10;
                }
                ++iNumber;
            }
        }
        return ret;
    }
};
