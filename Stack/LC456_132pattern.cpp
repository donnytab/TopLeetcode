// O(n)
// O(n)
// 输入：nums = [3,1,4,2]
// 输出：true
// 解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
// [单调栈]
//
//具体到本题的实现方式：
//
//求任何位置的左边最小的元素 nums[i] ，可以提前遍历一次而得到；
//使用「单调递减栈」，把 nums[j]  入栈时，需要把栈里面比它小的元素全都 pop 出来，由于越往栈底越大，所以 pop 出的最后一个元素，就是比 3 小的最大元素 nums[k] 。
//判断如果 nums[i] < nums[k] ，那就说明得到了一个 132 模式。
//因为单调栈是建立在 3 的右边的，因此，我们使用从右向左遍历。
//
class Solution {
    public:
        bool find132pattern(vector<int>& nums) {
            int n = nums.size();
            stack<int> candidate_k;
            candidate_k.push(nums[n - 1]);
            int max_k = INT_MIN;

            for (int i = n - 2; i >= 0; --i) {
                if (nums[i] < max_k) {
                    return true;
                }
                while (!candidate_k.empty() && nums[i] > candidate_k.top()) {
                    max_k = candidate_k.top();
                    candidate_k.pop();
                }
                if (nums[i] > max_k) {
                    candidate_k.push(nums[i]);
                }
            }

            return false;
        }
};
