// O(n)
// O(1)
// 输入：s = "abcd", t = "abcde"
// 输出："e"
// 解释：'e' 是那个被添加的字母。
class Solution {
public:
    char findTheDifference(string s. string t)
    {
        int iRet = 0;
        for (char cChar : s) { iRet ^= cChar; }
        for (char cChar : t) { iRet ^= cChar; }
        return iRet;
    }
};
