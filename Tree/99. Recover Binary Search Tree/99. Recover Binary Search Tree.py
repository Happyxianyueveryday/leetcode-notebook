# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        sta=[]

        count=0

        lastpos=None
        now=root
        pos1=None
        pos2=None

        while now:
            sta.append(now)
            now=now.left

        while sta:
            temp=sta[-1]
            sta.pop()

            if lastpos and temp.val<lastpos.val:
                if count==0:
                    pos1=lastpos
                    pos2=temp
                    count+=1
                else:
                    pos2=temp
                    count+=1
            else:
                lastpos=temp

            temp=temp.right

            while temp:
                sta.append(temp)
                temp=temp.left

        pos1.val, pos2.val=pos2.val, pos1.val

        return