/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题为非常经典的二叉树习题，一般使用标号法进行求解：假设根结点为i，则将其左子结点标记为i*2，将其右子结点标记为i*2+1
// 本题所使用的算法可以简述为：
// (1) 从根结点开始，对原树进行层次遍历，根结点标号为1，其他结点依次按照上述规则进行标号
// (2) 层次遍历结束后，依次计算各层最左侧结点和最右侧结点的标号之差，其中各层中最大的差值就是所求的二叉树的宽度

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        struct Node
        {
            Node(TreeNode *_root, unsigned int _depth, unsigned int _index):root(_root), depth(_depth), index(_index)
            {
            }
            TreeNode *root;
            unsigned int depth;
            unsigned int index;
        };

        queue<Node> que;
        vector<vector<int> > res;

        que.push(Node(root, 0, 1));

        while(que.size())
        {
            Node now=que.front();
            que.pop();

            if(now.depth>=res.size())
            {
                vector<int> temp;
                res.push_back(temp);
                res[now.depth].push_back(now.index);
            }
            else
                res[now.depth].push_back(now.index);
            
            if(now.root->left)
                que.push(Node(now.root->left, now.depth+1, now.index*2));
            if(now.root->right)
                que.push(Node(now.root->right, now.depth+1, now.index*2+1));
        }

        unsigned int max=0;
        for(int i=0;i<res.size();i++)
        {
            unsigned int temp=res[i][res[i].size()-1]-res[i][0]+1;
            max=(max>temp)?max:temp;
        }

        return max;
    }
};