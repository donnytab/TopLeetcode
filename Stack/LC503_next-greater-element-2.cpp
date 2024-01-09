// 输入: nums = [1,2,1]
// 输出: [2,-1,2]
// 解释: 第一个 1 的下一个更大的数是 2；
// 数字 2 找不到下一个更大的数； 
// 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
//
// 单调栈 + 循环数组
class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> ret(n, -1);
            stack<int> stk;
            for (int i = 0; i < n * 2 - 1; i++) {
                while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                    ret[stk.top()] = nums[i % n];
                    stk.pop();
                }
                stk.push(i % n);
            }
            return ret;
        }
};
