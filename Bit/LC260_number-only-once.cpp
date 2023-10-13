// C solution
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int xorsum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorsum ^= nums[i];
    }
    // 防止溢出
    int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
    int type1 = 0, type2 = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num & lsb) {
            type1 ^= num;
        } else {
            type2 ^= num;
        }
    }

    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = type1;
    ans[1] = type2;
    *returnSize = 2;
    return ans;
}

// C++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (int num: nums) {
            xorsum ^= num;
        }
        // 防止溢出
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (int num: nums) {
            if (num & lsb) {
                type1 ^= num;
            }
            else {
                type2 ^= num;
            }
        }
        return {type1, type2};
    }
};
