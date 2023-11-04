class Solution {
private:
// unordered_map<出发城市, map<到达城市, 航班次数>> targets
unordered_map<string, map<string, int>> targets;
bool backtracking(int ticketNum, vector<string>& result) {
    if (result.size() == ticketNum + 1) {      
        // 所以终止条件 我们回溯遍历的过程中，遇到的机场个数，如果达到了（航班数量 +1），
        // 那么我们就找到了一个行程，把所有航班串在一起了。
        return true;
    }
    for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
        if (target.second > 0 ) { // 使用int字段来记录到达城市是否使用过了
            result.push_back(target.first);
            target.second--;
            if (backtracking(ticketNum, result)) return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
}
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系,标记到达城市是否使用过了
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};
