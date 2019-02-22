# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        if not head or not head.next:
            return head

        newhead=ListNode(0)
        newhead.next=head
        head=newhead

        pos=head

        while pos and pos.next and pos.next.next:
            
            front=pos.next
            back=pos.next.next

            pos.next=back
            front.next=back.next
            back.next=front

            pos=front

        return head.next