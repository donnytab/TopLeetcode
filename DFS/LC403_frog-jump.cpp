// 记忆化搜索
//
//输入：stones = [0,1,3,5,6,8,12,17]
//输出：true
//解释：青蛙可以成功过河，按照如下方案跳跃：跳 1 个单位到第 2 块石子, 然后跳 2 个单位到第 3 块石子,
//接着 跳 2 个单位到第 4 块石子, 然后跳 3 个单位到第 6 块石子, 跳 4 个单位到第 7 块石子, 最后，跳 5 个单位到第 8 
//个石子（即最后一块石子）。]
//
// 使用一个哈希表 stone_pos 记录石子的位置，这样每次查找一个位置是否有石子只需要O(1)O(1)O(1)的时间
// 使用一个哈希表 visited 记录遍历过的状态，避免对相同的状态进行反复的访问，从而进行剪枝
// 使用一个变量 done 记录终止位置，一旦到达，立即跑路（指返回true
class Solution {
    public:
        unordered_map<int, unordered_set<int>> visited;
        unordered_set<int> stone_pos;
        int done;
        bool dfs(int prv_pos, int speed) {
            int cur_pos = prv_pos + speed;

            if(speed < 0 || !stone_pos.count(cur_pos))
                return false;
            if(visited[prv_pos].count(speed))
                return false;
            visited[prv_pos].insert(speed);

            if(cur_pos == done)
                return true;

            return dfs(cur_pos, speed-1) || 
                dfs(cur_pos, speed) || dfs(cur_pos, speed+1);   
        }
        bool canCross(vector<int>& stones) {
            int n = stones.size();
            stone_pos = unordered_set<int>(stones.begin(), stones.end());
            done = stones.back();

            return dfs(0, 1);
        }
};
