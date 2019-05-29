/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 较为基础的题目，由于二叉搜索树的中序遍历就能够得到递增的有序序列，因此直接使用中序遍历访问到第k个树的结点并返回其值即可

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> sta;

        TreeNode *temp=root;
        while(temp)
        {
            sta.push(temp);
            temp=temp->left;
        }

        int count=0;

        while(sta.size())
        {
            TreeNode *now=sta.top();
            sta.pop();

            count+=1;
            if(count==k)
            return now->val;

            temp=now->right;
            while(temp)
            {
                sta.push(temp);
                temp=temp->left;
            }
        }
        return -1;
    }
    
};