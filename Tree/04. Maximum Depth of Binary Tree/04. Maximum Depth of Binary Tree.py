# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 递归解法：树root的最大深度=max(左子树root.left的最大深度, 右子树root.right的最大深度)+1

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        elif not root.left and not root.right:
            return 1
        else:
            return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
        

# 非递归解法：使用层次遍历，在层次遍历的过程中记录队列中各个结点的深度信息，从而计算得到最大深度

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        que=[]    # 用于层次遍历的队列
        que.append([root,1])   # 在队列中记录root的深度为1

        depth=0   # 记录最终的树的最大深度

        while que:
            temp=que[0]
            que.pop(0)

            depth=temp[1] if temp[1]>depth else depth

            if temp[0].left:
                que.append([temp[0].left, temp[1]+1])
            if temp[0].right:
                que.append([temp[0].right, temp[1]+1])
        
        return depth