/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题同样是使用二叉搜索树中序遍历的性质进行求解
// 交换分为两种情况：第一种情况：交换两个不相邻的结点的值，以正常的二叉树的中序遍历序列为例：1,2,3,4,5,6，交换其中的2和5得到1,5,3,4,2,6；第二种情况，交换两个相邻的结点的值，以正常的二叉树的中序遍历序列为例：1,2,3，交换其中的1和2得到2,1,3
// 算法实现思路如下所示:
// 1. 中序遍历给定的二叉搜索树，记lastpos为上一次访问的结点的地址
// 2. 在遍历过程中第一次出现当前结点的值小于lastpos，则此时将lastpos作为交换了位置的结点，记为pos1，并将当前结点作为交换了位置的结点，记为pos2（这里记为pos2是为了上述介绍的相邻交换情况），然后更新lastpos
// 3. 在遍历过程中第一次出现当前结点的值小于lastpos，则此时将当前结点作为交换了位置的结点，记为pos2，然后更新lastpos
// 4. 最后直接交换pos1结点和pos2结点的值即可

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> sta;

        int count=0;            // 记录是第几次遇到当前结点的值小于lastpos的情况

        TreeNode *now=root;     // 中序遍历临时指针
        TreeNode *pos1=NULL;    // 交换了位置的结点1
        TreeNode *pos2=NULL;    // 交换了位置的结点2
        TreeNode *lastpos=NULL; // 上一次访问的结点

        while(now)
        {
            sta.push(now);
            now=now->left;
        }

        while(sta.size())
        {
            TreeNode *temp=sta.top();
            sta.pop();
            
            if(lastpos&&temp->val<lastpos->val)   // 注意判断lastpos是否为空
            {
                if(count==0)    // 第一次出现temp->val<lastpos->val的情况
                {
                    pos1=lastpos;
                    pos2=temp;
                    count+=1;
                }
                else            // 第二次出现temp->val<lastpos->val的情况
                {
                    pos2=temp;
                    count+=1;
                }
            }
            else
            lastpos=temp;

            temp=temp->right;
            while(temp)
            {
                sta.push(temp);
                temp=temp->left;
            }
        }

        // 交换两个出现错误的结点pos1和pos2的值
        int temp=pos1->val;
        pos1->val=pos2->val;
        pos2->val=temp;

        return;
    }
};