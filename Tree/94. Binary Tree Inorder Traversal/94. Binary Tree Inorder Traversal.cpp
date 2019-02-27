/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 最基础的树的相关问题：中序遍历，要求递归方法和非递归方法的实现思路都能够熟练的掌握，能够清晰地表述其实现算法

// 递归版本
// 递归版本的算法思路非常简单，对于一个树root，首先递归遍历其左子树，然后访问根节点，最后递归遍历其右子树即可
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;   //二叉树中序遍历结果

        // 1. 递归终止条件（递归奠基）
        if(!root)
        return res;

        else if(!root->left&&!root->right)
        {
            res.push_back(root->val);
            return res;
        }

        // 2. 递归递推条件（递归递推）
        else
        {
            // 2.1 生成左子树的中序遍历结果并加入结果数组中
            vector<int> left=inorderTraversal(root->left);
            for(int i=0;i<left.size();i++)
            {
                res.push_back(left[i]);
            }

            // 2.2 将根节点的值加入结果数组中
            res.push_back(root->val);
            
            // 2.3 生成右子树的中序遍历结果并加入结果数组中
            vector<int> right=inorderTraversal(root->right);
            for(int i=0;i<right.size();i++)
            {
                res.push_back(right[i]);
            }
            return res;
        }
    }
};


// 非递归版本
// 非递归版本的算法需要非常熟悉：
// 1. 使用一个栈来辅助遍历，首从根节点出发，先一直沿着左子节点，将过程中访问到的树的结点依次加入栈中
// 2. 循环执行以下步骤直到栈为空为止：从栈顶出栈一个结点，将该结点的值放入遍历结果中，从该结点的右子节点开始，一直沿着左子节点方向，将过程中访问到的树的结点依次加入栈中
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;         //二叉树中序遍历结果
        stack<TreeNode *> sta;   //二叉树中序遍历辅助栈

        //1. 使用一个栈来辅助遍历，首从根节点出发，先一直沿着左子节点，将过程中访问到的树的结点依次加入栈中
        TreeNode *now=root;
        while(now)
        {
            sta.push(now);
            now=now->left;
        }


        // 2. 循环执行以下步骤直到栈为空为止：从栈顶出栈一个结点，将该结点的值放入遍历结果中，从该结点的右子节点开始，一直沿着左子节点方向，将过程中访问到的树的结点依次加入栈中
        while(sta.size())
        {
            // 2.1 出栈栈顶结点并输出
            TreeNode *temp=sta.top();
            res.push_back(temp->val);
            sta.pop();

            // 2.2 将栈顶结点的右子结点，沿着左子结点的方向上的结点依次加入栈中
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