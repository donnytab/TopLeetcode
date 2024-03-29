// O(logn)
// O(1)
// 我们可以从二进制的角度进行分析：给定起始值 n，求解将其变为 (000...0001)2 的最小步数。
//
//   对于偶数（二进制最低位为 000）而言，我们只能进行一种操作，其作用是将当前值 xxx 其进行一个单位的右移；
//   对于奇数（二进制最低位为 111）而言，我们能够进行 +1 或 -1 操作，分析两种操作为 xxx 产生的影响：
//   对于 +1 操作而言：最低位必然为 111，此时如果次低位为 000 的话， +1 相当于将最低位和次低位交换；如果次低位为 111 的话，+1 操作将将「从最低位开始，连续一段的 111」进行消除（置零），并在连续一段的高一位添加一个 111；
//   对于 -1 操作而言：最低位必然为 111，其作用是将最低位的 111 进行消除。
//   因此，对于 xxx 为奇数所能执行的两种操作，+1 能够消除连续一段的 111，只要次低位为 111（存在连续段），应当优先使用 +1 操作，但需要注意边界 x=3x = 3x=3 时的情况（此时选择 -1 操作）。
//
//   1.偶数直接右移，只有一种选项
//   2.奇数+1或者-1，有两种选项。
//   显然，让每一步1的数目最少好处大，于是 0bxxx01 采用 -1； 0bxxx11 采用 +1；
//    特殊情况 3，按上述原则+1后两次右移共需3次；减一后只需一次右移共2次，因此3采用-1操作
class Solution {
public:
    int integerReplacement(int n) 
    {
        long lSize = n;
        int iAns = 0;
        while (lSize != 1)
        {
            if (lSize % 2 == 0)  // even
            {
                lSize >>= 1;
            }
            else
            {
                if (lSize != 3 && ((lSize >> 1) & 1) == 1) ++lSize;
                else --lSize;
            }
            ++iAns;
        }
        return iAns;
    }
};
