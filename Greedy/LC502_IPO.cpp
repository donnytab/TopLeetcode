// 贪心 + 最大堆
typedef pair<int,int> pii;

class Solution {
    public:
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            int n = profits.size();
            int curr = 0;
            priority_queue<int, vector<int>, less<int>> pq;
            vector<pii> arr;

            for (int i = 0; i < n; ++i) {
                arr.push_back({capital[i], profits[i]});
            }
            sort(arr.begin(), arr.end());
            for (int i = 0; i < k; ++i) {
                while (curr < n && arr[curr].first <= w) {
                    pq.push(arr[curr].second);
                    curr++;
                }
                if (!pq.empty()) {
                    w += pq.top();
                    pq.pop();
                } else {
                    break;
                }
            }

            return w;
        }
};
