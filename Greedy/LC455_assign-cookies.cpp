// 为了尽可能满足最多数量的孩子，从贪心的角度考虑，应该按照孩子的胃口从小到大的顺序依次满足每个孩子，
// 且对于每个孩子，应该选择可以满足这个孩子的胃口且尺寸最小的饼干。
// 
class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int m = g.size(), n = s.size();
            int count = 0;
            for (int i = 0, j = 0; i < m && j < n; i++, j++) {
                while (j < n && g[i] > s[j]) {
                    j++;
                }
                if (j < n) {
                    count++;
                }
            }
            return count;
        }
};

// 输入: g = [1,2,3], s = [1,1]
// 输出: 1
// 解释: 
// 你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
// 虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
// 所以你应该输出1。
