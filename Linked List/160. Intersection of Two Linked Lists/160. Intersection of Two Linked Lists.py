# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None
        
        posa=headA
        posb=headB

        while posa!=posb:
            if posa:
                posa=posa.next
            else:
                posa=headB
            
            if posb:
                posb=posb.next;
            else:
                posb=headA
        
        if posa:
            return posa
        else:
            return None