// 最长递增子序列
// dp[i] = max(dp[j]) + 1   // 0 < j < i && num[j] < num[i]
// input : 10 9 2 5 3 7 101
//   dp  : 1  1 1 2 2 3  4
//   O(n^2), O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


// 贪心 + 二分查找
// 考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，
// 因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
// 基于上面的贪心思路，我们维护一个数组 d[i]d[i]d[i] ，表示长度为 iii 的最长上升子序列的末尾元素的最小值，用 len\textit{len}len 记录目前最长上升子序列的长度，起始时 lenlenlen 为 111，d[1]=nums[0]d[1] = \textit{nums}[0]d[1]=nums[0]。
/*最后整个算法流程为：

设当前已求出的最长上升子序列的长度为 len\textit{len}len（初始时为 111），从前往后遍历数组 nums\textit{nums}nums，在遍历到 nums[i]\textit{nums}[i]nums[i] 时：

如果 nums[i]>d[len]\textit{nums}[i] > d[\textit{len}]nums[i]>d[len] ，则直接加入到 ddd 数组末尾，并更新 len=len+1\textit{len} = \textit{len} + 1len=len+1；

否则，在 ddd 数组中二分查找，找到第一个比 nums[i]\textit{nums}[i]nums[i] 小的数 d[k]d[k]d[k] ，并更新 d[k+1]=nums[i]d[k + 1] = \textit{nums}[i]d[k+1]=nums[i]。
*/
// O(nlogn), O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};

