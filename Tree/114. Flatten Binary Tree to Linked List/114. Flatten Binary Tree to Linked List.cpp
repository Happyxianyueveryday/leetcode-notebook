/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题同样是通过递归算法来进行: 首先将该树的根结点作为链表的首结点，然后将该树的左子树扁平化为链表left，再将该树的右子树扁平化为right，最后将left接在首结点后，right接在left后即可

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)        
        return;
        else
        {
            TreeNode *head=root;
            flatten(root->left);
            flatten(root->right);

            TreeNode *left=root->left;
            TreeNode *right=root->right;
            head->left=NULL;

            head->right=left;
            TreeNode *now=head;

            while(now->right)
            {
                now=now->right;
            }

            now->right=right;

            return;
        }
    }
};