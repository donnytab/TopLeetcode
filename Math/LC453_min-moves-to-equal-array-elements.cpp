// 最小操作次数使数组元素相等
// O(n)
// O(1)
// 正着需要操作n-1个加1，反着只需要减一个1
class Solution {
    public:
        int minMoves(vector<int>& nums) {
            int minNum = *min_element(nums.begin(),nums.end());
            int res = 0;
            for (int num : nums) {
                res += num - minNum;
            }
            return res;
        }
};
