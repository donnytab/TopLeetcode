// O(n^2)
// O(logn)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        std::sort(people.begin(), people.end(), [](const vector<int>& vectA, const vector<int>& vectB){
            return vectA[0] > vectB[0] || (vectA[0] == vectB[0] && vectA[1] < vectB[1]>);
        });
    }

    vector<vector<int>> vectAns;
    for (auto& vectPerson : people)
    {
        vectAns.insert(vectAns.begin() + vectPerson[1], vectPerson);
    }

    return vectAns;
};
