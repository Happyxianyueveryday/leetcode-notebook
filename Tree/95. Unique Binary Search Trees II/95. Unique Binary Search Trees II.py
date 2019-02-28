# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n:
            return self.buildTree(1,n)
        else:
            return []
    
    def buildTree(self,begin,end):
        if begin>end:
            return [None]
        elif begin==end:
            return [TreeNode(begin)]
        else:
            res=[]
            for i in range(begin,end+1):
                left=self.buildTree(begin,i-1)
                right=self.buildTree(i+1,end)

                for x in left:
                    for y in right:
                        root=TreeNode(i)    # 需要为左子树和右子树的每一个组合生成一个根节点，需要特别注意这一个易错点
                        root.left=x
                        root.right=y
                        res.append(root)
            return res