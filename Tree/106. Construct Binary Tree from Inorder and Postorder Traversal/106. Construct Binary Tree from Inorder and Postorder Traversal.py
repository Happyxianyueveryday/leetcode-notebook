# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 树类型中最重要的习题之一；仅凭借中序遍历不能确定唯一的二叉树，需要配合前序遍历或者中序遍历完成
# 根据中序遍历+前序遍历生成二叉树，或者根据中序遍历+后序遍历生成二叉树，是二叉树中的经典习题，需要熟练掌握，能够快速准确地实现

# 基本算法思想：
# 1. 选定后序遍历序列的最后一个元素，以该元素为值生成树的根节点
# 2. 在中序遍历序列中查找根节点的值出现的位置，从该位置开始将序列分为前后两半，前半段为根结点左子树的中序遍历，后半段为根节点右子树的中序遍历
# 3. 删除后序遍历序列的最后一个元素
# 4. 先根据中序遍历的后半段和后序遍历序列生成右子树
# 5. 再根据中序遍历的前半段和后序遍历序列生成左子树

# 附注: 为什么生成根节点后，先生成右子树再生成左子树? 答: 因为后序遍历中先访问左子节点，再访问右子结点，最后访问根节点，因此删除最后一个结点后，

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        # 0. 处理特殊情况，当中序遍历序列为空的时候，直接返回None
        if not inorder:
            return None
        
        # 1. 选定后序遍历序列的最后一个元素，以该元素为值生成树的根节点
        root=TreeNode(postorder[-1])

        # 2. 在中序遍历序列中查找根节点的值的位置，从该位置开始将序列分为前后两半，前半段为根结点左子树的中序遍历，后半段为根节点右子树的中序遍历
        index=inorder.index(postorder[-1])
        left=inorder[:index]
        right=inorder[index+1:]

        # 3. 删除后序遍历序列的最后一个元素
        postorder.pop()

        # 4. 先根据中序遍历的后半段和后序遍历序列生成右子树
        root.right=self.buildTree(right,postorder)

        # 5. 再根据中序遍历的前半段和后序遍历序列生成左子树
        root.left=self.buildTree(left,postorder)

        return root

        

        