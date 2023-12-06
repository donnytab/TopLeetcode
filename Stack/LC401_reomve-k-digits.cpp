// O(n)
// O(n)
class Solution {
    string removeKdigits(string num, int k)
    {
        vector<char> vectStack;  // use vector for stack to avoid reverse operation
        for (auto& digit : num)
        {
            while (vectStack.size() > 0 && vectStack.back() > digit && k)
            {
                vectStack.pop_back();
                --k;
            }
            vectStack.push_back(digit);
        }

        while (k--)
        {
            vectStack.pop_back();  // remove remaining digits until k=0
        }

        string strAns;
        bool bPreZero = true;
        for (auto& digit : vectStack)
        {
            if (digit == '0' && bPreZero)  // skip leading zeros
            {
                continue;
            }
            bPreZero = false;
            strAns += to_string(digit);
        }
        return strAns;
    }
};
