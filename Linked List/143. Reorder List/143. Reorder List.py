# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 本题是非典型的链表题，但是算法思路均是基于一些比较基础的链表题中所使用的方法
# 本题的算法设计思路如下：
# 1. 对于输入的链表，找到链表的中间结点
# 2. 将链表从中间结点分为两段，前半段的链表进行封口，后半段的链表结点依次加入一个栈中（从而实现倒序访问链表后半段的结点）
# 3. 创建一个游标指针now，使用该指针遍历前半段的每个链表结点，游标指针now每访问一个链表结点，就从栈中出栈一个链表结点，将该结点插入在指针now所指向的结点之后
# 4. 重复步骤3，直到栈为空为止，这时直接返回修改后的链表即可
# 附注： 由于本题中无需修改原始链表的头结点，因此可以无需使用头部哑结点的技巧

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        # 0. 判断链表长度为0或者长度为1的特殊情况
        if not head or not head.next:
            return
        
        # 1. 首先查找给定链表的中间结点
        fast=head
        slow=head

        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next
        
        # 2. 以中间结点slow为界，将链表划分为前半段（包含slow结点本身）和后半段，将前半段封口，将后半段结点依次入栈
        sta=[]

        now=slow.next    # 后半段链表结点依次入栈
        while now:
            sta.append(now)
            now=now.next

        slow.next=None   # 前半段链表封口

        # 3. 使用一个游标指针now遍历前半段链表，每次遍历到一个新的结点，则从栈顶取出一个结点插入到该结点后
        now=head
        while sta:
            temp=sta[-1]
            sta.pop()

            temp.next=now.next
            now.next=temp

            now=temp.next    # 更新游标指针
        
        return
        