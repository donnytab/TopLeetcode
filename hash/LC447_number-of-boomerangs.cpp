// O(n^2)
// O(n)
class Solution {
    public:
        int numberOfBoomerangs(vector<vector<int>> &points) {
            int ans = 0;
            for (auto &p : points) {
                unordered_map<int, int> cnt;
                for (auto &q : points) {
                    int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);  // 保留距离的平方
                    ++cnt[dis];
                }
                for (auto &[_, m] : cnt) {
                    ans += m * (m - 1);  // 排列公式
                }
            }
            return ans;
        }
};
