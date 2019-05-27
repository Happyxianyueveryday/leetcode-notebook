/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 非常经典的题目，这里推荐在掌握传统写法的基础上，掌握下面的这种简化版的高效写法，能够保证手写代码时的准确性
// 本题的简化版算法为: 由于前序遍历的访问顺序为: 根节点->左子树->右子树，因此只要对前序遍历的访问顺序稍作修改为: 根节点->右子树->左子树，进行一次修改后的前序遍历得到结果后，再将结果反转即可得到后序遍历序列

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> sta;
        vector<int> res;

        if(!root)
        return res;

        sta.push(root);

        while(sta.size())
        {
            TreeNode *now=sta.top();
            res.push_back(now->val);

            sta.pop();

            if(now->left)        // 因为需要修改前序遍历顺序为: 根节点->右子树->左子树，因此左子树首先入栈
            sta.push(now->left);
            if(now->right)
            sta.push(now->right);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};