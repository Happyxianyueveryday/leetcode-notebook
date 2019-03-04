# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 本题的算法思路较为直接，使用快慢双指针法，但是需要特别注意快慢双指针的初始化，不能全部初始化为head
# 0. 处理特殊情况，即给定的链表为空，或者给定的链表中只含有一个结点，这时显然不存在环
# 1. 使用双指针法，设置一个快指针和一个慢指针，快指针初始化为head->next->next，慢指针初始化为head，注意不能同时将快指针和慢指针同时指向head，否则下面地循环条件总是不成立
# 2. 快指针每次移动两步，慢指针每次移动一步，快指针每次移动两步
# 3. 循环进行步骤2，直到快指针指向空结点或者快指针等于慢指针为止
# 4. 若因为快指针指向空结点而退出循环，则给定的链表中不存在环
# 5. 若因为快指针等于慢指针而退出循环，则给定的链表中存在环

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        # 0. 处理特殊情况
        if not head or not head.next:
            return False
        
        fast=head.next.next    # 快指针初始化为head.next.next
        slow=head              # 慢指针初始化为head，注意不能同时将fast和slow同时初始化为head，否则无法进入下面的循环

        while fast!=slow and fast and fast.next:
            fast=fast.next.next   # 快指针一次移动两步
            slow=slow.next        # 慢指针一次移动一步

        if fast==slow:
            return True
        else:
            return False
        