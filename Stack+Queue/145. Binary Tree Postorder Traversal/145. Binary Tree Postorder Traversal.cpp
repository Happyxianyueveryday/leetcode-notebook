/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树的使用栈的前序，中序以及后序遍历是务必要熟练掌握的内容
// 基本算法原理: 
// 0. 创建一个栈，首先沿着根节点一路向左，将途经的结点全部入栈直到二叉树最左侧的一个结点为止，然后循环执行下列操作直到栈为空为止：
// 1. 从栈顶出栈一个结点，将该结点输出
// 2. 判断出栈后的栈顶结点的右子结点是否与步骤1中出栈的结点相等，若相等，则无需将该右子结点加入栈中，否则，将该右子结点加入栈中，并从该右子结点开始一路向左，将沿途的结点全部加入栈中

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> sta;
        vector<int> res;

        TreeNode *pos=root;

        while(pos)
        {
            sta.push(pos);
            pos=pos->left;
        }

        sta.push(pos);      // 注意后序遍历时需要将空结点也加入栈中

        while(sta.size())
        {
            TreeNode *temp=sta.top();

            if(temp)
            res.push_back(temp->val);

            sta.pop();
            
            if(sta.size())
            {
                TreeNode *right=sta.top()->right;  
                
                if(right!=temp)
                {
                    while(right)
                    {
                        sta.push(right);
                        right=right->left;
                    }
                    sta.push(right);
                }
            }
        }

        return res;
    }
};