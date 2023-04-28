class Solution {
private:
    vector<vector<int>> ans;
    vector<int> comb;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(0, n, k);
        return ans;
    }

    void dfs(int start, int num, int cnt) {
        if (cnt == 0) {
            ans.emplace_back(comb);
            return;
        }

        for (int i = start; i < num; ++i) {
            comb.emplace_back(i + 1);
            dfs(i + 1, num, cnt - 1);
            comb.pop_back();
        }
    }
};
