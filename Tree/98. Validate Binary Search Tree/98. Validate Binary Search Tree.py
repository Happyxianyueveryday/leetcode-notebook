# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        sta=[]

        lastval=float('-inf')

        now=root
        while now:
            sta.append(now)
            now=now.left

        while sta:
            temp=sta[-1]
            sta.pop()

            if temp.val<=lastval:
                return False
            else:
                lastval=temp.val

            temp=temp.right

            while temp:
                sta.append(temp)
                temp=temp.left
        
        return True