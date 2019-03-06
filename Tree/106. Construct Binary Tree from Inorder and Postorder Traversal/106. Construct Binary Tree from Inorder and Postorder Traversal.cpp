
// 基本算法思想：
// 1. 选定后序遍历序列的最后一个元素，以该元素为值生成树的根节点
// 2. 在中序遍历序列中查找根节点的值出现的位置，从该位置开始将序列分为前后两半，前半段为根结点左子树的中序遍历，后半段为根节点右子树的中序遍历
// 3. 删除后序遍历序列的最后一个元素
// 4. 先根据中序遍历的后半段和后序遍历序列生成右子树
// 5. 再根据中序遍历的前半段和后序遍历序列生成左子树

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size())
        return NULL;

        int tar=postorder[postorder.size()-1];
        
        TreeNode *root=new TreeNode(tar);

        int index=-1;

        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==tar)
            {
                index=i;
                break;
            }
        }

        vector<int> left;
        vector<int> right;

        for(int i=0;i<index;i++)
        {
            left.push_back(inorder[i]);
        }
        for(int i=index+1;i<inorder.size();i++)
        {
            right.push_back(inorder[i]);
        }

        postorder.pop_back();

        root->right=buildTree(right,postorder);
        root->left=buildTree(left,postorder);

        return root;
    }
};