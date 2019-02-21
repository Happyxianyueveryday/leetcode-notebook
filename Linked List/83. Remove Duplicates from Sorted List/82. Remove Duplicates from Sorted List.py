# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head

        pos=head
        
        while pos:
            now=pos.next

            while now and now.val==pos.val:
                now=now.next
            
            pos.next=now    # python无需像C++一样手动释放内存
            pos=now
        
        return head