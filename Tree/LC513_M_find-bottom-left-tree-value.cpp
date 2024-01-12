// DFS
// O(n)
// O(n)
// 因为我们先遍历左子树，然后再遍历右子树，所以对同一高度的所有节点，最左节点肯定是最先被遍历到的。
class Solution {
    public:
        void dfs(TreeNode *root, int height, int &curVal, int &curHeight) {  // height为当前节点高度
            if (root == nullptr) {
                return;
            }
            height++;
            dfs(root->left, height, curVal, curHeight);
            dfs(root->right, height, curVal, curHeight);
            if (height > curHeight) {
                curHeight = height;
                curVal = root->val;
            }
        }

        int findBottomLeftValue(TreeNode* root) {
            int curVal, curHeight = 0;
            dfs(root, 0, curVal, curHeight);
            return curVal;
        }
};
