# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 本题的关键在于将给出的定义转化为递归定义，然后根据递归方法进行求解
# 基本算法思路: 一个二叉树root的

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        elif not root.left and not root.right:
            return True
        else:
            if self.isBalanced(root.left) and self.isBalanced(root.right) and abs(self.depth(root.left)-self.depth(root.right))<=1:
                return True
            else:
                return False
    
    def depth(self,root):
        if not root:
            return 0
        elif not root.left and not root.right:
            return 1
        else:
            return max(self.depth(root.left),self.depth(root.right))+1