# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        # 0. 处理链表为空的情况(但凡链表题均需要优先注意该情况)
        if not head:
            return head

        # 1. 首先计算链表的结点总数
        size=0
        pos=head
        while pos:
            pos=pos.next
            size+=1
        
        # 2. 计算需要旋转的结点数目
        k=k%size

        if not k:     # 特殊情况: k==0时相当于没有结点需要进行旋转，此时直接返回原链表
            return head

        # 3. 使用快慢双指针法查找链表的倒数第k%size+1个结点
        fast=head
        slow=head

        for i in range(k+1):
            fast=fast.next
        
        while fast:
            fast=fast.next
            slow=slow.next
        
        # 4. 此时slow即为倒数的第k%size+1个结点，从该结点开始，将链表分为前后两个部分
        front=head        # 前半段链表
        back=slow.next    # 后半段链表
        backpos=back      # 后半段链表指针

        slow.next=None    # 前半段链表封口

        while backpos.next:
            backpos=backpos.next

        # 5. 将前半段链表连接到后半段链表后

        backpos.next=front

        return back
