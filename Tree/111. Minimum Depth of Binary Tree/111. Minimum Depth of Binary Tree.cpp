/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 同样是比较简单的一题递归的树问题，递归转化为同类子问题的方法非常简单: 一个树root的最小深度等于左子树最小深度和右子树最小深度中的较小值加1
// 注意只有从根结点到叶子结点的长度算作真实长度，而到空结点的不算

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
        return 0;
        else if(!root->left&&!root->right)
        return 1;
        else
        {
            int left=(root->left)? minDepth(root->left): INT_MAX;
            int right=(root->right)? minDepth(root->right): INT_MAX;

            int min=(left<right)?left:right;

            return (min+1);
        }
    }
};