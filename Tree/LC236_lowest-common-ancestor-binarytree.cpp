class Solution {
public:
    bool lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q); 
        TreeNode* right = lowestCommonAncestor(root->right, p, q); 
        if (left == nullptr && right == nullptr) return nullptr;
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
};
// O(n)
// O(n)
