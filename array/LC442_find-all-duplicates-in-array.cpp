// 使用正负号记录，一次遍历
// O(n)
// O(1)
class Solution {
    public:
        vector<int> findDuplicates(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans;
            for (int i = 0; i < n; ++i) {
                int x = abs(nums[i]);
                if (nums[x - 1] > 0) {     // did not check
                    nums[x - 1] = -nums[x - 1];
                }
                else {
                    ans.push_back(x);      // has been checked, so the second time
                }
            }
            return ans;
        }
};
