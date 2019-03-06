/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 树类型中最重要的习题之一；仅凭借中序遍历不能确定唯一的二叉树，需要配合前序遍历或者中序遍历完成
// 根据中序遍历+前序遍历生成二叉树，或者根据中序遍历+后序遍历生成二叉树，是二叉树中的经典习题，需要熟练掌握，能够快速准确地实现

// 基本算法思路：循环进行以下步骤，直到前序遍历数组为空为止：
// 1. 选择前序遍历序列的首元素
// 2. 在中序遍历序列中查找该首元素出现的位置，并根据该值生成树的根节点
// 3. 从该位置开始将中序遍历序列分为两段，前半段和后半段，同时从前序遍历序列中删除首元素（根节点的值）
// 4. 由前序遍历序列和前半段中序遍历序列，递归生成根节点的左子树
// 5. 由前序遍历序列和后半段中序遍历序列，递归生成根节点的右子树

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // 0. 处理特殊情况，即中序遍历序列为空的情况，直接返回空树
        if(!inorder.size())
        return NULL;

        // 1. 在中序遍历序列中查找前序遍历序列首元素出现的位置，并根据该值生成树的根节点
        TreeNode *root=new TreeNode(preorder[0]);
        int index=-1;

        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==preorder[0])
            {
                index=i;
                break;
            }
        }

        // 2. 删除前序遍历的第一个元素，即根节点的值
        preorder.erase(preorder.begin());

        // 3. 从该位置开始，将中序遍历序列分为两半，前半段为左子树的中序遍历序列，后半段为右子树的中序遍历序列
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
        
        // 4. 先由前半段中序遍历序列和前序遍历序列生成左子树
        root->left=buildTree(preorder,left);

        // 5. 再由前半段中序遍历序列和前序遍历序列生成左子树
        root->right=buildTree(preorder,right);
        
        return root;
    }
};