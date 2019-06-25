/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 非常经典的一道二叉树习题，本题的基本算法步骤如下：
// (1) 首先在左子树和右子树中分别递归地查找结点p和结点q的最近公共祖先
// (2) 若在左子树中和右子树中均查找到了最近公共祖先，则说明结点p和结点q分别在当前结点的左子树和右子树中，故直接返回当前结点作为最近公共祖先
// (3) 若在左子树中查找到了最近公共祖先，而右子树中未查找到（查找结果为NULL），则返回左子树中的查找结果作为最近公共祖先
// (4) 若在右子树中查找到了最近公共祖先，而左子树中未查找到（查找结果为NULL），则返回右子树中的查找结果作为最近公共祖先
// (5) 若在左子树和右子树中均为查找到，则说明不存在最近公共祖先，直接返回NULL

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q)
            return root;
        else
        {
            TreeNode *left=lowestCommonAncestor(root->left, p, q);
            TreeNode *right=lowestCommonAncestor(root->right, p, q);

            if(left&&right)
                return root;
            else if(left&&!right)
                return left;
            else if(right&&!left)
                return right;
            else
                return NULL;
        }
    }
};