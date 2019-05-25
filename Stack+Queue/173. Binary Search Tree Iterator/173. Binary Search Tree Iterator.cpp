/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 较为简单的一道习题，因为二叉搜索树的中序遍历得到的就是从小到大的序列，因此只需要使用二叉树的非递归中序遍历即可

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode *temp=root;

        while(temp)
        {
            sta.push(temp);
            temp=temp->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *now=sta.top();
        sta.pop();
        
        TreeNode *temp=now->right;

        while(temp)
        {
            sta.push(temp);
            temp=temp->left;
        }

        return now->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return sta.size();
    }

    private:
    stack<TreeNode *> sta;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */