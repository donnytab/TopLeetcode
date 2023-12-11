// O(nlogn)
// O(nlogn)
// 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
// 输出: 1
// 解释: 移除 [1,3] 后，剩下的区间没有重叠。
class Solution {
public:
    int eraseOverlapInterval(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // from small to big
        std::sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
                    return u[1] < v[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;  // non-overlapping count

        for (int i = 1; i < n; +i>) {
            if (intervals[i][0] >= right) {  // left bigger than right
                ++ans;
                right = intervals[i][1];
            }
        }

        return n - ans;
    }
};
