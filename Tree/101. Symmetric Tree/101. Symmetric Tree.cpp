/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题仍然属于非典型的树的问题，但是可以使用类似的递归思想进行求解，关于树相关问题的递归思想，推荐看github上关于树部分的递归思想解题的方法
// 基本算法思想，两个树root1和root2对称的递归定义是：根节点root1的值和root2相等，且树root1的左子树和root2的右子树对称，树root1的右子树和root2的左子树对称

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
        return true;
        else
        return symSubTree(root->left,root->right);
    }

    bool symSubTree(TreeNode *root1,TreeNode *root2)
    {
        // 1. 若root1和root2均为空结点，则两个子树对称；若root1和root2种仅有一个为空结点，则两个子树不对称
        if(!root1&&!root2)
        return true;
        else if(!root1&&root2||!root2&&root1)
        return false;

        // 2. 若两个子树均为非空，则若根节点的值相等，且树root1的左子树和root2的右子树对称且树root2的右子树和root1的左子树对称，则root1和root2对称，否则不对称
        else
        {
            if(root1->val==root2->val&&symSubTree(root1->left,root2->right)&&symSubTree(root1->right,root2->left))
            return true;
            else
            return false;
        }
    }
};