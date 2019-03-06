/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 较为简单的题目，只需要根据题目中给出的递归定义，给出递归实现即可
// 算法基本思路：对于给定的二叉树，若该树的根节点的左子树和右子树都是平衡二叉树，且左子树和右子树的高度相差的绝对值小于或者等于1，即称该树为平衡二叉树
// 附注：需要特别强调必须是每个结点的左子树和右子树的高度都相差1的情况下才是平衡树，而并非只需要根节点的左子树和右子树的高度相差1

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
        return true;
        else if(!root->left&&!root->right)
        return true;
        else
        {
            // 若左子树是平衡树，右子树是平衡树
            if (isBalanced(root->left)&&isBalanced(root->right)&&abs(depth(root->left)-depth(root->right))<=1)
            return true;
            else
            return false;
        }
    }
    
    // 方法depth: 返回树的最大深度
    int depth(TreeNode *root)
    {
        if(!root)
        return 0;
        else if (!root->left&&!root->right)
        return 1;
        else
        {
            int leftdepth=depth(root->left);
            int rightdepth=depth(root->right);
            return ((leftdepth>rightdepth)?leftdepth:rightdepth)+1;
        }
    }
};