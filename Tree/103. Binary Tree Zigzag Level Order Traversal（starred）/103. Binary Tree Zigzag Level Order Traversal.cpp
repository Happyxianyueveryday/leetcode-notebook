/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题是非常重要的二叉树相关习题，普通的二叉树层次遍历是使用队列，而本题中是使用一个栈和一个队列，非常有效地考察了考生的知识迁移能力，凡是需要考虑倒序输出的地方，都应该考虑使用栈这种数据结构来进行处理
// 基本算法思路：创建双栈来解决逆序问题，当层数为奇数时，从栈1中依次出栈结点并输出，然后将这些结点的左右子结点放入栈2中；当层数为偶数时，从栈2中出栈元素并输出，然后将出栈结点的左右子结点放入栈1中，循环执行上述步骤直到栈和队列均为空为止，每一次循环输出给定树中一层的结点
// 附注：本题的算法极为经典，需要注意熟练掌握，能够熟练地应用队列顺序输出和栈倒序输出的特性，本题每一层之间的输出关系都是倒序，所以应该首先想到用栈的方式进行解答

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // 0. 创建结果数组
        vector<vector<int> > res;   // 遍历结果数组

        // 1. 处理特殊情况，即当给定的树为空树的情况
        if(!root)
            return res;

        // 2. 创建一个遍历所使用的双栈
        stack<TreeNode*> sta1;   // 遍历中使用的临时栈1，用于存放奇数层结点
        stack<TreeNode*> sta2;   // 遍历中使用的临时栈2，用于存放偶数行结点

        sta2.push(root);         // 根节点的层数为0，将其放入栈2中

        // 3. 循环进行下面的步骤直到双栈均为空，则输出完毕，每一次循环输出一层的结点
        int index=0;   // 当前输出的层数
        while (sta1.size()||sta2.size())
        {
            vector<int> tempres;   // 本层的遍历结果

            // 3.1 若所在的层数为偶数，则从栈2中出栈结点，并将这些结点的左右子节点加入栈1
            if(index%2==0)
            {
                while(sta2.size())
                {
                    // 从栈2中出栈结点
                    TreeNode *temp=sta2.top();  
                    sta2.pop();
                    
                    // 输出结点
                    tempres.push_back(temp->val);

                    // 将子结点入栈1，偶数行先左后右，至于为什么请使用题目给出的示例数据来尝试和分析
                    if(temp->left)
                    sta1.push(temp->left);
                    if(temp->right)
                    sta1.push(temp->right);
                }
            }


            // 3.2 若所在的层数为偶数，则从栈1中出栈结点，并将这些结点的左右子节点加入栈2
            else
            {
                while(sta1.size())
                {
                    // 从栈1出栈结点
                    TreeNode *temp=sta1.top();
                    sta1.pop();

                    // 输出结点
                    tempres.push_back(temp->val);

                    // 将子结点入栈2，奇数行先右后左，至于为什么请使用题目给出的示例数据来尝试和分析
                    if(temp->right)
                    sta2.push(temp->right);
                    if(temp->left)
                    sta2.push(temp->left);
                }
            }

            // 3.3 将本层的结点输出加入结果中，并且更新层数
            index+=1;
            res.push_back(tempres);
        }

        return res;
    }
};