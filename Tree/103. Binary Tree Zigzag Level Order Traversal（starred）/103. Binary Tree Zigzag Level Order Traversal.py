# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        # 1. 创建结果数组并处理特殊情况
        res=[]
        
        if not root:
            return res

        # 2. 创建两个栈odd和even，栈odd用于装入奇数层的结点，栈even用于装入偶数层的结点，设根节点的层数为0
        odd=[]
        even=[]
        
        even.append(root)   # 将根结点入偶数栈

        index=0             # 当前层数，记根节点的层数为0

        # 3. 循环输出结点，每一次循环输出一层的结点，直到奇数栈和偶数栈均为空时，输出完毕并退出循环
        while odd or even:
            tempres=[]    #本层的层次遍历结果

            # 3.1 若本层为奇数层，则从奇数栈中出栈结点并输出，然后将结点的左右子节点加入偶数栈中
            if index%2:
                while odd:
                    temp=odd[-1]
                    odd.pop()

                    tempres.append(temp.val)

                    if temp.right:   # 奇数层先右后左
                        even.append(temp.right)
                    if temp.left:
                        even.append(temp.left)
            
            # 3.2 若本层为偶数层，则从偶数栈中出栈结点并输出，然后将结点的左右子节点加入奇数栈中
            else:
                while even:
                    temp=even[-1]
                    even.pop()

                    tempres.append(temp.val)

                    if temp.left:   # 偶数层先左后右
                        odd.append(temp.left)
                    if temp.right:
                        odd.append(temp.right)
            
            # 3.3 将本层的遍历结果加入总的遍历结果res中，并更新当前层数
            res.append(tempres)
            index+=1;
            

        return res
                

                

