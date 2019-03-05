# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 一分钟内需要准确无误写出来的题目，不然准备回家种地，具体算法见代码，不作过多解释

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        que=[]
        res=[]

        que.append((root,0))    # 注意记录深度信息
        
        while que:
            temp=que[0]
            que.pop(0)

            # 注意这里多维数组结果的构建方法
            if temp[1]>=len(res):
                res.append([temp[0].val])
            else:
                res[temp[1]].append(temp[0].val)


            if temp[0].left:
                que.append((temp[0].left,temp[1]+1))
            if temp[0].right:
                que.append((temp[0].right,temp[1]+1))
        return res
        