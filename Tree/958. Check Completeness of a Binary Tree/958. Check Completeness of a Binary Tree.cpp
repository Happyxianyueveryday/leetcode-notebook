/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 一般直接使用标号法来判断二叉树是否为完全二叉树：设根结点的标号为i，则将根结点的左子结点标号为2*i，右子结点标号为2*i+1
// 具体标号法的步骤可以简述如下：
// (1) 从根结点开始，将根结点标号为1
// (2) 对原树进行层次遍历，输出当前结点，遍历过程中入队的结点依次按照上述标号规则进行标号
// (3) 上述层次遍历结束后，若得到从1开始的自然数序列，则原树为完全二叉树，否则原树不为完全二叉树

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        
        queue<pair<TreeNode *, unsigned int> > que;   // 推荐使用unsigned int来避免可能存在的溢出问题
        vector<unsigned int> res;

        que.push(make_pair(root, 1));

        while(que.size())
        {
            pair<TreeNode *, unsigned int> now=que.front();
            que.pop();

            res.push_back(now.second);

            if(now.first->left)
                que.push(make_pair(now.first->left, 2*now.second));
            if(now.first->right)
                que.push(make_pair(now.first->right, 2*now.second+1));
        }

        for(int i=0;i<res.size();i++)
        {
            if(res[i]!=i+1)
                return false;
        }

        return true;
    }
};