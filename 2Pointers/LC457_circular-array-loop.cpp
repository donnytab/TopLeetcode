// O(n)
// O(1)
// 输入：nums = [2,-1,1,2,2]
// 输出：true
// 解释：存在循环，按下标 0 -> 2 -> 3 -> 0 。循环长度为 3 。
class Solution {
    public:
        bool circularArrayLoop(vector<int>& nums) {
            int n = nums.size();
            auto next = [&](int cur) {
                return ((cur + nums[cur]) % n + n) % n; // 保证返回值在 [0,n) 中
            };

            for (int i = 0; i < n; i++) {
                if (!nums[i]) {
                    continue;
                }
                int slow = i, fast = next(i);
                // 判断非零且方向相同
                while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                    if (slow == fast) {
                        if (slow != next(slow)) {
                            return true;
                        } else {
                            break;
                        }
                    }
                    slow = next(slow);
                    fast = next(next(fast));
                }
                int add = i;
                while (nums[add] * nums[next(add)] > 0) {
                    int tmp = add;
                    add = next(add);
                    nums[tmp] = 0;
                }
            }
            return false;
        }
};
