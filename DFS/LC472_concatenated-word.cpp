//
//输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
//解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成; 
//     "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成; 
//          "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
//
// 字典树 + 记忆化搜索
// 按照字符串的长度递增的顺序排序，排序后可以确保当遍历到任意单词时，比该单词短的单词一定都已经遍历过，因此可以根据已经遍历过的全部单词判断当前单词是不是连接词。
// 判断一个单词是不是连接词的做法是在字典树中搜索。从该单词的第一个字符（即下标 000 处的字符）开始，在字典树中依次搜索每个字符对应的结点，可能有以下几种情况：
//
// 如果一个字符对应的结点是单词的结尾，则找到了一个更短的单词，从该字符的后一个字符开始搜索下一个更短的单词；
//
// 如果一个字符对应的结点在字典树中不存在，则当前的搜索结果失败，回到上一个单词的结尾继续搜索。
//
// 如果找到一个更短的单词且这个更短的单词的最后一个字符是当前单词的最后一个字符，则当前单词是连接词

struct Trie {
    bool isEnd;
    vector<Trie *> children;
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
};

class Solution {
    public:
        Trie * trie = new Trie();

        vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
            vector<string> ans;
            sort(words.begin(), words.end(), [&](const string & a, const string & b){
                    return a.size() < b.size(); 
                    });
            for (int i = 0; i < words.size(); i++) {
                string word = words[i];
                if (word.size() == 0) {
                    continue;
                }
                vector<int> visited(word.size(), 0);
                if (dfs(word, 0, visited)) {
                    ans.emplace_back(word);
                } else {
                    insert(word);
                }
            }
            return ans;
        }

        bool dfs(const string & word, int start, vector<int> & visited) {
            if (word.size() == start) {
                return true;
            }
            if (visited[start]) {
                return false;
            }
            visited[start] = true;
            Trie * node = trie;
            for (int i = start; i < word.size(); i++) {
                char ch = word[i];
                int index = ch - 'a';
                node = node->children[index];
                if (node == nullptr) {
                    return false;
                }
                if (node->isEnd) {
                    if (dfs(word, i + 1, visited)) {
                        return true;
                    }
                }
            }
            return false;
        }

        void insert(const string & word) {
            Trie * node = trie;
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                int index = ch - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new Trie();
                }
                node = node->children[index];
            }
            node->isEnd = true;
        }
};
