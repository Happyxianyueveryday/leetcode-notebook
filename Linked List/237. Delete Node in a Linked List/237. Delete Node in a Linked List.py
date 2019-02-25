# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 本题主要考察在不给定前驱结点的情况下，如何从链表中删除一个结点
# 删除的思路和算法都较为简单，就是从待删除结点开始，将每一个结点的值设定称这个结点的下一个结点的值，然后，删除最后一个结点的值

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        now=node        # 链表指针
        lastnow=None    # now的前驱结点

        # 1. 从待删除的结点开始，将每一个结点的值置换为该结点的后继结点的值，直到到达最后一个结点位置(后继结点不存在)
        while now.next:
            now.val=now.next.val
            lastnow=now
            now=now.next

        # 2. 到达最后一个结点之后，通过游标指针now的前驱结点lastnow删除该结点
        lastnow.next=None

