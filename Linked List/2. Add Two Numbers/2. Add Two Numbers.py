# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 1. 处理其中一个链表为空的情况，仅需返回另外一个链表即可
        if not l1:
            return l2
        if not l2:
            return l1
        
        # 2. 设置两个链表指针，从链表头结点开始依次对对应的链表结点相加
        res=ListNode(0)   # 结果链表，同样使用哑结点来进行代码简化
        carrier=0         # 来自于上一位相加结果的进位数值
        respos=res        # 结果链表指针
        pos1=l1           # 链表1指针
        pos2=l2           # 链表2指针

        while pos1 or pos2 or carrier:
            # 2.1 计算本位结果和进位
            temp=(pos1.val if pos1 else 0)+(pos2.val if pos2 else 0)+carrier
            print(temp)
            value=temp%10
            carrier=temp//10   #注意python3中的整数除法为双斜线
            respos.next=ListNode(value)
            
            # 2.2 更新各个链表的指针
            pos1=pos1.next if pos1 else pos1
            pos2=pos2.next if pos2 else pos2
            respos=respos.next

        return res.next
        
        

        