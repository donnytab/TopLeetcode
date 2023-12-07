// 由题意可知：子数组的最大值是有范围的，即在区间 [max(nums),sum(nums)][max(nums),sum(nums)][max(nums),sum(nums)] 之中。
// 令 l=max(nums)，h=sum(nums)l=max(nums)，h=sum(nums)l=max(nums)，h=sum(nums)，mid=(l+h)/2mid=(l+h)/2mid=(l+h)/2，计算数组和最大值不大于mid对应的子数组个数 cnt(这个是关键！)
// 如果 cnt>m，说明划分的子数组多了，即我们找到的 mid 偏小，故 l=mid+1l=mid+1l=mid+1；
// 否则，说明划分的子数组少了，即 mid 偏大(或者正好就是目标值)，故 h=midh=midh=mid。
int splitArray(vector<int>& nums, int m) {
    long l = nums[0], h = 0;//int类型在这里不合适，因为h可能会超过int类型能表示的最大值
    for (auto i : nums)
    {
        h += i;
        l = l > i ? l : i;
    }
    while (l<h)
    {
        long mid = (l + h) / 2;
        long temp = 0;
        int cnt = 1;//初始值必须为1
        for(auto i:nums)
        {
            temp += i;
            if(temp>mid)
            {
                temp = i;
                ++cnt;
            }
        }
        if(cnt>m)
            l = mid + 1;
        else
            h = mid;
    }
    return l;
}


class Solution {
    public:
        bool check(vector<int>& nums, int x, int m) {
            long long sum = 0;
            int cnt = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (sum + nums[i] > x) {
                    cnt++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            return cnt <= m;
        }

        int splitArray(vector<int>& nums, int m) {
            long long left = 0, right = 0;
            for (int i = 0; i < nums.size(); i++) {
                right += nums[i];
                if (left < nums[i]) {
                    left = nums[i];
                }
            }
            while (left < right) {
                long long mid = (left + right) >> 1;
                if (check(nums, mid, m)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }
};
