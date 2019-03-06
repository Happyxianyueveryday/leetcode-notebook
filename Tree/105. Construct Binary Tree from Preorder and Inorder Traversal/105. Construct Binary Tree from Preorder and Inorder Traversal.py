# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        # 0. 处理特殊情况，当中序遍历序列为空，这时树为空树，直接返回None
        if not inorder:
            return None
        
        # 1. 由前序遍历序列的第一个元素生成根节点
        root=TreeNode(preorder[0])

        # 2. 在中序遍历序列中查找根节点的值所在的位置，从该位置将中序遍历序列分为前后两段，前半段为左子树的中序遍历序列，后半段为右子树的中序遍历序列
        index=inorder.index(preorder[0])

        left=inorder[:index]
        right=inorder[index+1:]

        # 3. 从前序遍历序列中删除第一个元素，即根节点的值
        preorder.pop(0)

        # 4. 先根据前半段中序遍历序列和前序遍历序列生成左子树
        root.left=self.buildTree(preorder,left)

        # 4. 再根据后半段中序遍历序列和前序遍历序列生成右子树
        root.right=self.buildTree(preorder,right)
        
        return root