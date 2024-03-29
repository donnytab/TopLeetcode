class Solution {
    public:
        string frequencySort(string s) {
            unordered_map<char, int> mp;
            for(auto ch:s) mp[ch]++;
            sort(s.begin(),s.end(),[&](const char &a, const char &b){
                    return mp[a]==mp[b] ? a>b : mp[a]>mp[b];
                    });
            return s;
        }
};


// 桶排序
class Solution {
    public:
        string frequencySort(string s) {
            unordered_map<char, int> mp;
            int maxFreq = 0;
            int length = s.size();
            for (auto &ch : s) {
                maxFreq = max(maxFreq, ++mp[ch]);
            }
            vector<string> buckets(maxFreq + 1);
            for (auto &[ch, num] : mp) {
                buckets[num].push_back(ch);
            }
            string ret;
            for (int i = maxFreq; i > 0; i--) {
                string &bucket = buckets[i];
                for (auto &ch : bucket) {
                    for (int k = 0; k < i; k++) {
                        ret.push_back(ch);
                    }
                }
            }
            return ret;
        }
};
