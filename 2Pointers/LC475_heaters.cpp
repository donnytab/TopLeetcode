// 贪心 + 双指针
// O(mlogm + nlogn)
// O(logm + logn)
//
//我们需要保证每个房屋至少在一个加热器的供暖范围内，那为了让加热半径最小，我们只需要保证每个房屋最近的加热器的距离小于加热半径。
//那全局最低的加热半径；自然也就等于所有房屋到最近加热器的距离中的最大值。 这是一个min(max)的问题。
//
// 如果我们的房屋和加热器都是按照横坐标排序的；那显然，我们只需要顺次对每个房子找和他相邻的前后两个加热器即可。
// 用两个指针分别标记房屋和加热器；不断移动加热器，直至加热器的横坐标大于房屋横坐标。 则当前加热器指针 cur 和 cur-1 就是房屋左边的加热器和右边的加热器。
// 我们求两者到房屋距离中的较小值，就是该房屋最近的加热器到房屋的距离。
//
// 遍历所有的房屋，取最大值即可。
class Solution {
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            sort(houses.begin(), houses.end());
            sort(heaters.begin(), heaters.end());
            int ans = 0;
            for (int i = 0, j = 0; i < houses.size(); i++) {
                int curDistance = abs(houses[i] - heaters[j]);
                while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                    j++;
                    curDistance = min(curDistance, abs(houses[i] - heaters[j]));
                }
                ans = max(ans, curDistance);
            }
            return ans;
        }
};
