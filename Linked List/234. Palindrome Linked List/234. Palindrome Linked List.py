# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 0. 处理特殊情况
        if not head or not head.next:
            return True

        # 1. 使用双指针法求解链表的中间结点
        fast=head
        slow=head
        slowback=None

        while fast and fast.next:
            fast=fast.next.next
            slowback=slow
            slow=slow.next

        # 2. 从中间结点开始，将链表划分为前后半段总共两段
        slowback.next=None
        front=head
        back=slow

        # 3. 将后半部分链表进行反转
        now=back.next
        nowback=back

        while now:
            nowback.next=now.next
            now.next=back
            back=now
            now=nowback.next
        
        # 4. 依次比较使用指针比较反转后的后半部分链表和前半部分链表的每个结点
        pos1=back
        pos2=front

        while pos1 and pos2:
            if pos1.val!=pos2.val:
                return False
            else:
                pos1=pos1.next
                pos2=pos2.next
        
        return True
        

