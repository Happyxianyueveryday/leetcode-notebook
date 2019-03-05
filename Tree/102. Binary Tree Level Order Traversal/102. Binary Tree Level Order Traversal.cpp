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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;    // 结果遍历数组

        // 0. 处理特殊情况，若树为空，则直接返回空的列表
        if(!root)
        return res;

        // 1. 创建一个队列，在队列中同时记录结点和结点所在的深度，首先将树的根节点加入队列
        queue<pair<TreeNode *,int> > que;   // 用于层次遍历的队列 
        que.push(make_pair(root,0));
        
        // 2. 每次从队列中出栈一个结点，并输出该结点，若该结点的左子树不为空，则将左子树加入队列中，加入时深度信息+1，若该结点的右子树不为空，则将右子树加入队列中，加入时深度信息+1，
        while(que.size())
        {
            pair<TreeNode *,int> temp=que.front();
            que.pop();

            // 2.1 输出当前出队的结点
            if(temp.second>=res.size())
            {
                vector<int> tempres;
                tempres.push_back(temp.first->val);
                res.push_back(tempres);
            }
            else
            res[temp.second].push_back(temp.first->val);
            
            // 2.2 若不为空结点，将当前结点的左子结点和右子结点加入队列
            if(temp.first->left)
            que.push(make_pair(temp.first->left,temp.second+1));
            if(temp.first->right)
            que.push(make_pair(temp.first->right,temp.second+1));
        }
        
        return res;
    }
};