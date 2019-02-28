/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树中最为经典的算法：检查一个二叉树是否为二叉搜索树
// 具体算法是：直接按照中序遍历算法遍历二叉树，判断得到的序列是否为递增序列，若为递增序列则给定的树为二叉搜索树，否则不是二叉搜索树

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> sta;

        int lastval;   // 上一次访问结点的值
        int flag=0;

        TreeNode *now=root;
        while(now)
        {
            sta.push(now);
            now=now->left;
        }

        while(sta.size())
        {
            TreeNode *temp=sta.top();
            sta.pop();
            
            if(flag&&temp->val<=lastval)
            return false;
            else
            lastval=temp->val;

            temp=temp->right;
            while(temp)
            {
                sta.push(temp);
                temp=temp->left;
            }

            flag=1;
        }
        return true;
    }
};