class Solution {
public:
    int longestPalindrome(string s)
    {
        int iAns = 0, iOdd = 0;
        unordered_map<char, int> umapPalin;
        for (auto& chChar : s)
        {
            ++umapPalin[chChar];
        }

        for (auto pair : umapPalin)
        {
            int iVal = pair.second;
            iAns += iVal / 2 * 2;
            if (iVal % 2 == 1)
            {
                iOdd = 1;
            }
        }
        // 若当前字符出现次数为奇数，则将 odd 置 1
        iAns += iOdd;
        return iAns;
    }
};
