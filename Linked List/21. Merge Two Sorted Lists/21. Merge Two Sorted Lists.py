# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 1. 处理两个链表中存在空链表的情况，若一个链表为空，则直接返回另一个链表
        if not l1:
            return l2
        if not l2:
            return l1
        
        # 2. 处理一般情况，创建结果数组，并创建三个指针——链表1的指针，链表2的指针以及结果链表的指针
        pos1=l1             # 链表1的指针
        pos2=l2             # 链表2的指针
        res=ListNode(0)     # 结果链表，包含哑结点
        respos=res          # 链表指针

        # 3. 首先，当两个指针均不指向空结点时，对两个指针指向的结点值进行比较，将较小值放入结果链表，然后更新加入结果的链表结点的指针以及结果链表的指针
        while pos1 and pos2:
            min=pos1.val if pos1.val<pos2.val else pos2.val
            respos.next=ListNode(min)
            
            if pos1.val<pos2.val:
                pos1=pos1.next
            else:
                pos2=pos2.next
            respos=respos.next

        # 3. 然后，若存在指针指向空结点，说明其中一个链表中的结点值已经全部加入结果链表中，这时将剩下的没有完全加入的链表中的结点依次加入结果链表中
        while pos1:
            respos.next=ListNode(pos1.val)

            pos1=pos1.next
            respos=respos.next
        
        while pos2:
            respos.next=ListNode(pos2.val)

            pos2=pos2.next
            respos=respos.next
        
        return res.next