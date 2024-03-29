// O(m+n)
// O(n)
// 单调栈 + 哈希表
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int,int> hashmap;
            stack<int> st;
            for (int i = nums2.size() - 1; i >= 0; --i) {
                int num = nums2[i];
                while (!st.empty() && num >= st.top()) {
                    st.pop();
                }
                hashmap[num] = st.empty() ? -1 : st.top();
                st.push(num);
            }
            vector<int> res(nums1.size());
            for (int i = 0; i < nums1.size(); ++i) {
                res[i] = hashmap[nums1[i]];
            }
            return res;
        }
};
