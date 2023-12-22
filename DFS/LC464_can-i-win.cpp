// 输入：maxChoosableInteger = 10, desiredTotal = 11
// 输出：false解释：
// 无论第一个玩家选择哪个整数，他都会失败。
// 第一个玩家可以选择从 1 到 10 的整数。
// 如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
// 第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
// 同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
class Solution {
    public:
        unordered_map<int, bool> memo;

        bool canIWin(int maxChoosableInteger, int desiredTotal) {
            if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {
                return false;
            }
            return dfs(maxChoosableInteger, 0, desiredTotal, 0);
        }

        bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal) {
            if (!memo.count(usedNumbers)) {
                bool res = false;
                for (int i = 0; i < maxChoosableInteger; i++) {
                    if (((usedNumbers >> i) & 1) == 0) {
                        if (i + 1 + currentTotal >= desiredTotal) {
                            res = true;
                            break;
                        }
                        if (!dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1)) {
                            res = true;
                            break;
                        }
                    }
                }
                memo[usedNumbers] = res;
            }
            return memo[usedNumbers];
        }
};
