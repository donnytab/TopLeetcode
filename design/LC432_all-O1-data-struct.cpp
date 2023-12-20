// O(1)
// O(1)
class AllOne {
    list<pair<unordered_set<string>, int>> lst;
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> nodes;

    public:
    AllOne() {}

    void inc(string key) {
        if (nodes.count(key)) {
            auto cur = nodes[key], nxt = next(cur);
            if (nxt == lst.end() || nxt->second > cur->second + 1) {
                unordered_set<string> s({key});
                nodes[key] = lst.emplace(nxt, s, cur->second + 1);
            } else {
                nxt->first.emplace(key);
                nodes[key] = nxt;
            }
            cur->first.erase(key);
            if (cur->first.empty()) {
                lst.erase(cur);
            }
        } else { // key 不在链表中
            if (lst.empty() || lst.begin()->second > 1) {
                unordered_set<string> s({key});
                lst.emplace_front(s, 1);
            } else {
                lst.begin()->first.emplace(key);
            }
            nodes[key] = lst.begin();
        }
    }

    void dec(string key) {
        auto cur = nodes[key];
        if (cur->second == 1) { // key 仅出现一次，将其移出 nodes
            nodes.erase(key);
        } else {
            auto pre = prev(cur);
            if (cur == lst.begin() || pre->second < cur->second - 1) {
                unordered_set<string> s({key});
                nodes[key] = lst.emplace(cur, s, cur->second - 1);
            } else {
                pre->first.emplace(key);
                nodes[key] = pre;
            }
        }
        cur->first.erase(key);
        if (cur->first.empty()) {
            lst.erase(cur);
        }
    }

    string getMaxKey() {
        return lst.empty() ? "" : *lst.rbegin()->first.begin();
    }

    string getMinKey() {
        return lst.empty() ? "" : *lst.begin()->first.begin();
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/all-oone-data-structure/solutions/1335680/quan-o1-de-shu-ju-jie-gou-by-leetcode-so-7gdv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。)))))))}}}}}