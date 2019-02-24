# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        # 1. 处理特殊情况
        if not head:
            return head
        
        # 2. 为链表头结点增加一个哑结点
        newhead=ListNode(0)
        newhead.next=head
        head=newhead

        # 3. 依次遍历链表结点并且检查是否需要进行删除
        lastpos=head      # 游标指针pos的前驱结点
        pos=head.next     # 游标指针pos
        while pos:
            if pos.val==val:
                lastpos.next=pos.next
                lastpos=lastpos    # 特别注意两种情况下lastpos游标指针的更新方法
                pos=pos.next
            else:
                lastpos=pos
                pos=pos.next

        return head.next
            