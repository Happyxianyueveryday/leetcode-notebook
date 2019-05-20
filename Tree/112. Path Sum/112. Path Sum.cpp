/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 一道较为简单的题，同样使用递归思想做，若左子树或者右子树中存在从根到叶子结点的路径之和为(sum-root->val)，则返回true，否则返回false

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
        return false;
        else if(!root->left&&!root->right)
        return (sum==root->val);
        else
        {
            int tar=sum-root->val;
            return (hasPathSum(root->left, tar)||hasPathSum(root->right, tar));
        }
    }
};