# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 本题的思路较为基础，主要考察链表的反转方法：
# 对于单向链表而言，链表的标准反转方法是依次将原始链表的头结点后的每一个结点插入到原始链表中头结点的前驱结点之前，例如1->2->3, 2->1->3, 3->2->1
# 对于双向链表而言，链表的标准反转方法是直接将每个结点的back指针和next指针的值进行交换

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        # 0. 处理特殊情况：当m==n时，无需反转链表，直接进行返回即可
        if m==n:
            return head

        # 1. 将原始链表增加一个哑结点
        newhead=ListNode(0)
        newhead.next=head
        head=newhead

        pos=head     # 原始链表游标指针

        # 2. 查找待反转部分链表的第一个结点的前驱结点pos
        for i in range(m-1):
            pos=pos.next
        
        # 现在pos指向待反转部分的第一个结点的前驱结点
        now=pos.next  # 创建第二个游标指针now，初始化为待反转链表部分的头节点，注意到m==n的特殊情况已经处理过了，因此pos.next必定不为NULL
        swap=now.next    # pos，now以及swap之间的关系为:pos->now->swap->...，其中now为要反转链表片段的第一个结点

        for i in range(n-m):    # 注意n>=m的基本关系，这里容易出错
            # 将swap插入到待反转部分链表头节点的前驱结点pos之后，pos->now->swap->...反转为pos->swap->now->...
            now.next=swap.next
            swap.next=pos.next
            pos.next=swap

            # 更新下一个要反转插入的结点
            swap=now.next

        return head.next


 

        
        
        
        