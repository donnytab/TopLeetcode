// mask位数与num相同后，执行异或操作，相同为0，不同为1，即1->0，0->1。
class Solution {
    public:
        int findComplement(int num) {
            int mask = 1;
            while(mask < num) {
                mask <<= 1;
                mask |= 1;
            }
            return mask ^ num;
        }
};
