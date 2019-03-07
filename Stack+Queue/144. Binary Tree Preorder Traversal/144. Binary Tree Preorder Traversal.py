# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res=[]
        sta=[]

        if not root:
            return res
        
        sta.append(root)

        while sta:
            temp=sta[-1]
            sta.pop()

            res.append(temp.val)

            if temp.right:
                sta.append(temp.right)
            if temp.left:
                sta.append(temp.left)
        
        return res