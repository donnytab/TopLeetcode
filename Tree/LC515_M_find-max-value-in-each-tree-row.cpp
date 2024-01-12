// 我们用树的「先序遍历」来进行「深度优先搜索」处理，并用 curHeight 来标记遍历到的当前节点的高度。当遍历到 curHeight高度的节点就判断是否更新该层节点的最大值。
class Solution {
    public:
        void dfs(vector<int>& res, TreeNode* root, int curHeight) {
            if (curHeight == res.size()) {
                res.push_back(root->val);
            } else {
                res[curHeight] = max(res[curHeight], root->val);
            }
            if (root->left) {
                dfs(res, root->left, curHeight + 1);
            }
            if (root->right) {
                dfs(res, root->right, curHeight + 1);
            }
        }

        vector<int> largestValues(TreeNode* root) {
            if (!root) {
                return {};
            }
            vector<int> res;
            dfs(res, root, 0);
            return res;
        }
};
