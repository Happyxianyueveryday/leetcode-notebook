# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 反转链表是最为基础的数据结构链表考察题目，在各类面试中经常出现，需要非常熟悉链表反转的基本算法，并且能够白板快速写出代码

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # 1. 处理链表中为空或者只有一个元素的特殊情况
        if not head or not head.next:
            return head

        # 2. 为原始链表增加哑结点
        newhead=ListNode(0)
        newhead.next=head
        head=newhead
        
        # 3. 从待反转链表的第二个结点开始，将每一个结点从原位置删除，然后插入到哑结点head后
        orihead=head.next    # 反转前的原始链表的首结点
        
        swap=orihead.next
        
        while swap:
            orihead.next=swap.next
            swap.next=head.next
            head.next=swap
            
            swap=orihead.next
        
        return head.next
        

            