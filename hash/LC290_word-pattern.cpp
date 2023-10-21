/*
 *思路： 
 1.定义两个map，为何定义两个呢？ 防止[aaaa]与[cat dog dog cat]、[abba]与[cat cat cat cat]时输出true 
 2.用stringstream可以自动输出词组 
 3.判断：!(ss >> s)判断pattern长度是否大于str长度，且将ss容器中字符串赋值给s 
 4.判断：(map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) 来判断是否匹配 
 5.判断：(ss >> s) ? false : true 判断str长度是否大于pattern长度
 *
 *
 * */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(str); string s;
        for(char c : pattern) {
            if(!(ss >> s) || (map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) return false;
            map[c] = s; rmap[s] = c;
        }
        return (ss >> s) ? false : true;
    }
};
