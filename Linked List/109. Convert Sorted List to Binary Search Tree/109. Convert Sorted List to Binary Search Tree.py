# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        
        # 1. 处理叶子结点和空结点的情况
        if not head:
            return None
        elif head and not head.next:
            root=TreeNode(head.val)
            return root

        # 2. 快慢双指针法找到链表的中间结点
        fast=head    # 快指针
        slow=head    # 慢指针
        lastslow=None  # 慢指针的前驱结点

        while fast and fast.next:
            lastslow=slow

            fast=fast.next.next
            slow=slow.next

        # 3. 根据链表的中间结点生成树的根节点
        root=TreeNode(slow.val)
        
        # 4. 根据前半段链表和后半段链表生成根节点的左子树和右子树
        lastslow.next=None    # 前半段链表封口

        root.left=self.sortedListToBST(head)
        root.right=self.sortedListToBST(slow.next)
        
        return root
        