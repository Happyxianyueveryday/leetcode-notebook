# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        # 1. 处理特殊情况，即head==None的情况
        if not head:
            return head

        # 2. 创建一个比给定值的小的结点的链表low和比给定值大的结点的链表high，同时创建游标指针lowpos和highpos
        pos=head          # 原始链表的游标指针
        low=ListNode(0)   # 给定值的小的结点的链表low
        high=ListNode(0)  # 比给定值大的结点的链表high

        lowpos=low        # 链表low的游标指针
        highpos=high      # 链表high的游标指针

        while pos:
            if pos.val<x:
                lowpos.next=ListNode(pos.val)
                lowpos=lowpos.next
            
            else:
                highpos.next=ListNode(pos.val)
                highpos=highpos.next
            
            pos=pos.next
        
        lowpos.next=high.next
        return low.next