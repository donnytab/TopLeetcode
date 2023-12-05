// O(n)
// O(n)
// 输入：input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
// 输出：32
// 解释：存在两个文件：
// "dir/subdir1/file1.ext" ，路径长度 21
// "dir/subdir2/subsubdir2/file2.ext" ，路径长度 32
// 返回 32 ，因为这是最长的路径
class Solution {
    int lengthLongestPath(string input) {
        int iSz = input.size();
        int iPos = 0, iAns = 0;
        vector<int> vectLevel(n + 1);
        int iLen = 0;
        bool bFile = false;

        while (iPos < iSz)
        {
            // check file depth
            int iDepth = 1;
            while (iPos < n && input[iPos] == '\t')
            {
                ++iPos;
                ++iDepth;
            }

            // calculate filename length
            while (iPos < n && input[iPos] != '\n')
            {
                if (input[iPos] == '.')
                {
                    bFile = true;
                }
                ++iLen;
                ++iPos;
            }

            ++iPos;  // skip \t

            if (iDepth > 1)
            {
                iLen += vectLevel[iDepth - 1] + 1; // add 1 for '/'
            }

            if (bFile)
            {
                iAns = max(iAns, iLen);
            }
            else
            {
                vectLevel[iDepth] = iLen;
            }
        }
        return iAns;
    }
};
