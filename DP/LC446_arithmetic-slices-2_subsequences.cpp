// 等差数列划分
// 输入：nums = [2,4,6,8,10]
// 输出：7
// 解释：所有的等差子序列为：
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]
//
// O(n^2)
// O(n^2)
class Solution {
    public:
        int numberOfArithmeticSlices(vector<int> &nums) {
            int ans = 0;
            int n = nums.size();
            vector<unordered_map<long long, int>> f(n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    long long d = 1LL * nums[i] - nums[j];
                    auto it = f[j].find(d);
                    int cnt = it == f[j].end() ? 0 : it->second;
                    ans += cnt;
                    f[i][d] += cnt + 1;
                }
            }
            return ans;
        }
};
