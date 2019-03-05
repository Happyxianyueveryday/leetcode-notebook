# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 1. 创建两个栈，将两个链表中的元素依次入栈
        sta1=[]
        sta2=[]

        pos1=l1
        pos2=l2

        while pos1:
            sta1.append(pos1.val)
            pos1=pos1.next
            

        while pos2:
            sta2.append(pos2.val)
            pos2=pos2.next

        # 2. 从栈中依次出栈元素并按照同样的方法进行相加
        res=ListNode(0)      # 含有哑结点的结构链表头
        carrier=0            # 来自上一位的进位数值

        while sta1 or sta2 or carrier:
            if sta1:
                value1=sta1[-1]
                sta1.pop()
            else:
                value1=0
            if sta2:
                value2=sta2[-1]
                sta2.pop()
            else:
                value2=0
            
            tempres=(value1+value2+carrier)%10
            carrier=(value1+value2+carrier)/10
            
            newnode=ListNode(tempres)
            newnode.next=res.next
            res.next=newnode

        return res.next

            

            