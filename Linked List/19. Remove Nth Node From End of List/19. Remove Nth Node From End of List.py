# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """

        fast=head    # 快指针
        slow=head    # 慢指针

        # 1. 快指针移动n步
        for i in range(n):
            fast=fast.next
        
        # 2. 判断快指针是否移动到末尾，即fast==None，若fast==None，则待删除的是头结点，特殊处理删去头结点
        if fast==None:
            head=head.next    # 与C或者C++不同，python无需手动释放内存
            return head
        # 2. 若fast!=None，则同时移动快指针和慢指针，直到fast->next==None，这时slow指向待删除结点的前驱结点
        else:
            while fast.next!=None:
                fast=fast.next
                slow=slow.next
            slow.next=slow.next.next
            return head
            
        