/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 经典到不能再经典的习题，此处不再重复说明算法步骤

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> sta;
        vector<int> res;
        TreeNode *now=root;

        while(now)
        {
            sta.push(now);
            now=now->left;
        }

        while(sta.size())
        {
            TreeNode *temp=sta.top();
            res.push_back(temp->val);

            sta.pop();

            temp=temp->right;
            while(temp)
            {
                sta.push(temp);
                temp=temp->left;
            }
        }

        return res;
    }
};