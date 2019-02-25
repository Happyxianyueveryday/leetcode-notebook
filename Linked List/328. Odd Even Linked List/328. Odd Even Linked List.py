# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 1. 处理特殊情况
        if not head or not head.next:
            return head
        
        # 2. 创建一个游标指针now，指向原始链表的第二个结点，以及游标指针lastnow，该指针指向now指针的前驱结点
        now=head.next
        lastnow=head
        insert=head     # 奇数结点的插入点

        # 3. 从原位置删除结点now.next，然后将该结点插入到插入点之后，然后更新now指针和插入点指针insert
        while now and now.next:
            swap=now.next

            now.next=swap.next
            swap.next=insert.next
            insert.next=swap

            insert=insert.next
            now=now.next
        
        return head
        

        

        