/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树中的基本题型：使用递归即可，一个二叉树root的最大深度等于左子树root.left的深度以及右子树root.right中的深度中的最大值加上1


// 递归解法：
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0;
        else if(!root->left&&!root->right)
        return 1;
        else
        {
            int leftdepth=maxDepth(root->left);
            int rightdepth=maxDepth(root->right);

            return ((leftdepth>rightdepth)?leftdepth:rightdepth)+1;
        }
    }
};


// 下面同样提供一种非递归解法，面试中，树的递归方法的非递归实现也是一个考点
// 非递归算法思想：可以利用树的层次遍历方法，使用一个队列实现层次遍历时，向队列中加入树的结点时同样加入深度信息，从而进行求解

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0;
        
        queue<pair<TreeNode*, int> > que;   //用于层次遍历的栈
        que.push(make_pair(root,1));        //将根节点加入队列中

        int depth=1;                        //记录树的最大深度

        while(que.size())
        {
            // 从队列中出队一个树的结点并输出，更新树的最大深度
            pair<TreeNode*, int> temp=que.front();
            que.pop();

            depth=(temp.second>depth)?temp.second:depth;

            // 将出队的结点的左子结点和右子结点加入队列，入队时，记录这两个结点的深度+1
            if(temp.first->left)    // 注意空结点无需加入队列
            que.push(make_pair(temp.first->left,temp.second+1));
            if(temp.first->right)   // 注意空结点无需加入队列
            que.push(make_pair(temp.first->right,temp.second+1));
        }

        return depth;
    }
};