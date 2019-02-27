# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 非递归版本

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        elif not root.left and not root.right:
            return [root.val]
        else:
            return self.inorderTraversal(root.left)+[root.val]+self.inorderTraversal(root.right)


# 递归版本

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        elif not root.left and not root.right:
            return [root.val]
        else:
            res=[]    # 中序遍历结果
            sta=[]    # 辅助遍历栈
            # 1. 从根节点开始，沿着左子节点方向，将所有访问到的结点加入结果链表中
            now=root
            while now:
                sta.append(now)
                now=now.left
            
            while sta:
                temp=sta[-1]
                sta.pop()

                res.append(temp.val)

                temp=temp.right
                while temp:
                    sta.append(temp)
                    temp=temp.left
            return res
                
                
