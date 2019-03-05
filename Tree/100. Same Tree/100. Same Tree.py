# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 本题的难度较小，可以直接使用递归进行求解，二叉树root1和root2相等，只需要根节点相等，左子树和右子树分别相等即可

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """

        if not p and not q:
            return True
        elif not p and q:
            return False
        elif not q and p:
            return False
        else:
            if self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right) and p.val==q.val:
                return True
            else:
                return False


        