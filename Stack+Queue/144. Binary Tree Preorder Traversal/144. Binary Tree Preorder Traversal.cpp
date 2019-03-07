/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 较为基础的二叉树以及栈的题目，需要能够熟练使用栈来进行二叉树的前序，中序，后序遍历
// 基本算法思路：使用栈进行二叉树的前序遍历的基本步骤是：首先将二叉树的根节点放入栈中，然后循环进行下面的操作知道栈为空为止：从栈顶出栈一个元素，将该元素输出，然后分别将该结点的右子结点和左子结点入栈

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> sta;
        vector<int> res;
        
        if(!root)
        return res;

        sta.push(root);

        while(sta.size())
        {
            TreeNode *temp=sta.top();
            
            res.push_back(temp->val);
            
            sta.pop();

            if(temp->right)
            sta.push(temp->right);
            if(temp->left)
            sta.push(temp->left);
        }

        return res;
    }
};