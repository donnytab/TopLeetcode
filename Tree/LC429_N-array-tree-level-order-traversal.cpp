// O(n)
// O(n)
class Solution {
  public:
    vector<vector<int>> levelOrder(Node* root) {
      if (!root) {
        return {};
      }

      vector<vector<int>> ans;
      queue<Node*> q;
      q.push(root);

      while (!q.empty()) {
        int cnt = q.size();
        vector<int> level;
        for (int i = 0; i < cnt; ++i) {
          Node* cur = q.front();
          q.pop();
          level.push_back(cur->val);
          for (Node* child: cur->children) {
            q.push(child);
          }
        }
        ans.push_back(move(level));
      }

      return ans;
    }
};
