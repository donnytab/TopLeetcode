class Solution {
    public:
        int rootSum(TreeNode* root, long target) {
            if (!root) return 0;

            int iRet = 0;
            if (target == root->value) {
                ++iRet;
            }
            iRet += rootSum(root->left, target - root->value);
            iRet += rootSum(root->right, target - root->value);
            return iRet;
        }

        int pathSum(TreeNode* root, int target) {
            if (!root) return 0;

            int iRet = rootSum(root, target);
            iRet += rootSum(root->left, target);
            iRet += rootSum(root->right, target);

            return iRet;
        }
};

// O(n)
// O(n)
class Solution {
    public:
        unordered_map<long long, int> prefix;

        int dfs(TreeNode *root, long long curr, int targetSum) {
            if (!root) {
                return 0;
            }

            int ret = 0;
            curr += root->val;
            if (prefix.count(curr - targetSum)) {
                ret = prefix[curr - targetSum];
            }

            prefix[curr]++;
            ret += dfs(root->left, curr, targetSum);
            ret += dfs(root->right, curr, targetSum);
            prefix[curr]--;

            return ret;
        }

        int pathSum(TreeNode* root, int targetSum) {
            prefix[0] = 1;
            return dfs(root, 0, targetSum);
        }
};
