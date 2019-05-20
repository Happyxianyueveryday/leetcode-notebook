/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 本题中所使用的算法非常简单: 将数组的中间元素作为根节点，由数组的前半部分元素递归生成根结点的左子树，由数组的后半部分元素递归生成根结点的右子树即可

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())
        return NULL;
        else if(nums.size()==1)
        {
            TreeNode *root=new TreeNode(nums[0]);
            return root;
        }
        else
        {
            vector<int> left, right;

            int mid=nums.size()/2;
            TreeNode *root=new TreeNode(nums[mid]);

            for(int i=0;i<nums.size();i++)
            {
                if(i<mid)
                left.push_back(nums[i]);
                else if(i>mid)
                right.push_back(nums[i]);
            }

            root->left=sortedArrayToBST(left);
            root->right=sortedArrayToBST(right);

            return root;
        }
    }
};