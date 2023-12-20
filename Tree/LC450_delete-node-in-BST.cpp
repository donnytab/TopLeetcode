//如果目标节点大于当前节点值，则去右子树中删除；
//如果目标节点小于当前节点值，则去左子树中删除；
//如果目标节点就是当前节点，分为以下三种情况：
//    其无左子：其右子顶替其位置，删除了该节点；
//    其无右子：其左子顶替其位置，删除了该节点；
//    其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置，由此删除了该节点。
//
// O(n)
// O(n)
// 递归法
class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == nullptr) {
                return nullptr;
            }
            if (root->val > key) {
                root->left = deleteNode(root->left, key);
                return root;
            }
            if (root->val < key) {
                root->right = deleteNode(root->right, key);
                return root;
            }
            if (root->val == key) {
                if (!root->left && !root->right) {
                    return nullptr;
                }
                if (!root->right) {
                    return root->left;
                }
                if (!root->left) {
                    return root->right;
                }
                TreeNode *successor = root->right;
                while (successor->left) {
                    successor = successor->left;  // 找右子树中的最小节点
                }
                root->right = deleteNode(root->right, successor->val);  // 删除successor
                successor->right = root->right;
                successor->left = root->left;
                return successor;
            }
            return root;
        }
};



class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) 
        {
            if (root == nullptr)    return nullptr;
            if (key > root->val)    root->right = deleteNode(root->right, key);     // 去右子树删除
            else if (key < root->val)    root->left = deleteNode(root->left, key);  // 去左子树删除
            else    // 当前节点就是要删除的节点
            {
                if (! root->left)   return root->right; // 情况1，欲删除节点无左子
                if (! root->right)  return root->left;  // 情况2，欲删除节点无右子
                TreeNode* node = root->right;           // 情况3，欲删除节点左右子都有 
                while (node->left)          // 寻找欲删除节点右子树的最左节点
                    node = node->left;
                node->left = root->left;    // 将欲删除节点的左子树成为其右子树的最左节点的左子树
                root = root->right;         // 欲删除节点的右子顶替其位置，节点被删除
            }
            return root;    
        }
};



// 迭代法
// O(n)
// O(1)
class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            TreeNode *cur = root, *curParent = nullptr;
            while (cur && cur->val != key) {
                curParent = cur;
                if (cur->val > key) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }
            if (!cur) {
                return root;
            }
            if (!cur->left && !cur->right) {
                cur = nullptr;
            } else if (!cur->right) {
                cur = cur->left;
            } else if (!cur->left) {
                cur = cur->right;
            } else {
                TreeNode *successor = cur->right, *successorParent = cur;
                while (successor->left) {
                    successorParent = successor;
                    successor = successor->left;
                }
                if (successorParent->val == cur->val) {
                    successorParent->right = successor->right;
                } else {
                    successorParent->left = successor->right;
                }
                successor->right = cur->right;
                successor->left = cur->left;
                cur = successor;
            }
            if (!curParent) {
                return cur;
            } else {
                if (curParent->left && curParent->left->val == key) {
                    curParent->left = cur;
                } else {
                    curParent->right = cur;
                }
                return root;
            }
        }
};
