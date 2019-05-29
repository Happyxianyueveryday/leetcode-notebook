/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树中非常经典的问题，主要的解决算法也非常简单
// 本题的基本算法步骤可以简述为: 从根结点开始，依次比较当前结点和结点p和结点q的值:
// (1) 若当前结点now的值小于p和q中的较小值，则说明结点p和结点q都在当前结点的右子树中，因此递归地到now->right中查找
// (2) 若当前结点now的值大于p和q中的较大值，则说明结点p和结点q都在当前结点的左子树中，因此递归地到now->left中查找
// (3) 若当前结点now的值在p和q之间（包括p和q），则说明当前结点就是结点p和结点q的最近公共祖先，因此直接返回当前结点now即可

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min=(p->val<q->val)?p->val:q->val;
        int max=(p->val>q->val)?p->val:q->val;

        if(!root)
        return NULL;
        else if(root->val<min)
        return lowestCommonAncestor(root->right, p, q);
        else if(root->val>max)
        return lowestCommonAncestor(root->left, p, q);
        else
        return root;
    }
};