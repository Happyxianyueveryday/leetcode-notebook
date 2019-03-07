# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # 1. 处理特殊情况，当根节点为空时，直接返回空列表作为遍历结果
        res=[]
        
        if not root:
            return res
        
        # 2. 从根节点开始一路向左，将所有的途经结点均加入栈中，注意最后再向栈中加入一个空结点
        sta=[]
        
        pos=root
        while pos:
            sta.append(pos)
            pos=pos.left
        sta.append(pos)

        # 3. 从栈顶出栈一个结点temp，然后判断出栈后的新栈顶结点的右子结点right是否与temp相等，若相等则栈顶结点的右子树已经输出完成，这时无需做任何操作；若不相等，则这时栈顶结点的右子树尚未输出，这时从结点right开始一路向左，将途经的结点加入栈中，最后再向栈内加入一个空结点
        while sta:

            temp=sta[-1]
            sta.pop()

            if temp:
                res.append(temp.val)

            if sta:
                right=sta[-1].right

                if temp!=right:
                    while right:
                        sta.append(right)
                        right=right.left
                    sta.append(right)
            
        return res