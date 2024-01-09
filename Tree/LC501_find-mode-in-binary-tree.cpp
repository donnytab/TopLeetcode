// 二叉搜索树的众数
// 用morris中序遍历把空间复杂度降低到O(1)
// 关键步骤：先遍历当前节点的前驱节点，再遍历当前节点
// MORRIS模板如下：
/*
   TreeNode *cur = root, *pre = nullptr;
   while (cur) {
   if (!cur->left) {
// ...遍历 cur
cur = cur->right;
continue;
}
pre = cur->left;
while (pre->right && pre->right != cur) {
pre = pre->right;
}
if (!pre->right) {
pre->right = cur;
cur = cur->left;
} else {
pre->right = nullptr;
// ...遍历 cur
cur = cur->right;
}
}
*/

// 如果当前节点没有左子树，则遍历这个点，然后跳转到当前节点的右子树。
// 如果当前节点有左子树，那么它的前驱节点一定在左子树上，我们可以在左子树上一直向右行走，找到当前点的前驱节点。
//     如果前驱节点没有右子树，就将前驱节点的 right指针指向当前节点。这一步是为了在遍历完前驱节点后能找到前驱节点的后继，也就是当前节点。
//     如果前驱节点的右子树为当前节点，说明前驱节点已经被遍历过并被修改了 right指针，这个时候我们重新将前驱的右孩子设置为空，遍历当前的点，然后跳转到当前节点的右子树。
class Solution {
    public:
        int base, count, maxCount;
        vector<int> answer;

        void update(int x) {
            if (x == base) {
                ++count;
            } else {
                count = 1;
                base = x;
            }
            if (count == maxCount) {
                answer.push_back(base);
            }
            if (count > maxCount) {
                maxCount = count;
                answer = vector<int> {base};
            }
        }

        vector<int> findMode(TreeNode* root) {
            TreeNode *cur = root, *pre = nullptr;
            while (cur) {
                if (!cur->left) {
                    update(cur->val);
                    cur = cur->right;
                    continue;
                }
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    update(cur->val);
                    cur = cur->right;
                }
            }
            return answer;
        }
};
