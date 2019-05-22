/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// 非常基础和简单的递归题目: 要翻转二叉树root，只需要先将左子树root->left进行递归地翻转，再将右子树root->right进行递归地翻转，最后交换root->left和root->right即可

class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root==null)
        return root;
        else if(root.left==null&&root.right==null)
        return root;
        else
        {
            root.left=invertTree(root.left);
            root.right=invertTree(root.right);

            TreeNode temp=root.left;
            root.left=root.right;
            root.right=temp;
            
            return root;
        }
    }
}