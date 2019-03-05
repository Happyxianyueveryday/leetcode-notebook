/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 检验是否为相同的树的方式较为简单，一般使用递归方法：树root1和树root2相等，当且仅当根节点相等，左子树和右子树对应相等
// 附注：使用输出空结点的遍历也可以验证两个树相等，在这里略去

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)
        return true;
        else if(p&&!q||q&&!p)
        return false;
        else
        {
            if(isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)&&p->val==q->val)
            return true;
            else
            return false;
        }
    }
};