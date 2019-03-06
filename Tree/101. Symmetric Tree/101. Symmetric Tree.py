# 本题仍然属于非典型的树的问题，但是可以使用类似的递归思想进行求解，关于树相关问题的递归思想，推荐看github上关于树部分的递归思想解题的方法
# 基本算法思想，两个树root1和root2对称的递归定义是：根节点root1的值和root2相等，且树root1的左子树和root2的右子树对称，树root1的右子树和root2的左子树对称


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        else:
            return self.symSubTree(root.left,root.right)
    
    def symSubTree(self,root1,root2):
        if not root1 and not root2:
            return True
        elif not root1 and root2 or not root2 and root1:
            return False
        else:
            return root1.val==root2.val and self.symSubTree(root1.left,root2.right) and self.symSubTree(root1.right,root2.left)
        