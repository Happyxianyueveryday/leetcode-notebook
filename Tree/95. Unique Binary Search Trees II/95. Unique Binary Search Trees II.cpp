/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题为非常典型的二叉树类型的题目：考察n个结点的不同二叉搜索树的构型有多少种
// 本题所使用的思路较为简单，使用递归思路解决问题
// 对于n个结点的二叉搜索树，其所有的结点的取值范围为[1,n]，则按照如下的算法生成所有可能的二叉树
// 1. 选取范围[1,n]内的一个整数值k作为根节点
// 2. 从范围[1,k-1]产生所有可能的二叉搜索树，根节点的左子树可以为这些结果中的任何一个
// 3. 从范围[k+1,n]产生所有可能的二叉搜索树，根节点的右子树可以为这些结果中的任何一个
// 4. 将所有可能的左子树，右子树和根节点结合，得到的若干个二叉搜索树就是所求的结果

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> res;
        if(n==0)
        return res;
        else
        return buildTrees(1,n);
    }

    // buildTrees方法: 生成结点值在范围[begin, end]的二叉搜索树
    vector<TreeNode *> buildTrees(int begin, int end)
    {
        vector<TreeNode *> res;    // 最终产生的结果的列表

        // 1. 递归奠基：若begin>end，直接返回空结点；若begin==end，直接返回单个结点的树
        if(begin>end)
        {
            res.push_back(NULL);
            return res;
        }
        else if(begin==end)
        {
            TreeNode *root=new TreeNode(begin);
            res.push_back(root);
            return res;
        }
        else
        {
            for(int i=begin;i<=end;i++)
            {
                vector<TreeNode *> left=buildTrees(begin,i-1);   // 递归生成根节点的可选左子树，由于其中的每个左子树都是递归生成的，因此不存在两个子树共享某一个相同的结点的问题，这里需要特别注意
                vector<TreeNode *> right=buildTrees(i+1,end);    // 递归生成根节点的可选右子树

                for(int k=0;k<left.size();k++)
                {
                    for(int m=0;m<right.size();m++)
                    {
                        // 必须为每一个左右子树的组合重新生成一个新的根节点，而不能由多个左右子树组合共享一个根节点
                        TreeNode *root=new TreeNode(i);   
                        // 连接根节点和可选的左子树和右子树组合
                        root->left=left[k];
                        root->right=right[m];
                        // 将生成的二叉搜索树放入结果数组中
                        res.push_back(root);
                    }
                }
            }
            return res;
        }
    }
};