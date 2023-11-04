// 递增的三元子序列
// 为了找到递增的三元子序列，first 和 second 应该尽可能地小，此时找到递增的三元子序列的可能性更大。
// 根据上述分析可知，当遇到 num>second 时，一定存在一个递增的三元子序列，该三元子序列的第二个数和第三个数分别是 second 和 num，因此返回 true
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            if (num > second) {
                return true;
            } else if (num > first) {
                second = num;
            } else {
                first = num;
            }
        }
        return false;
    }
};
