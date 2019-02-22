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
        
        # 1. 处理空链表或者只有单个元素的链表
        if not head or not head.next:
            return head

        # 2. 为原始链表加上头部哑结点
        newhead=ListNode(0)
        newhead.next=head
        head=newhead

        # 3. 创建链表游标指针
        pos=head.next     # 初始化链表游标指针为首结点，该游标指针只会指向相同值的结点中的第一个结点
        lastpos=head      # 链表游标指针pos的前驱结点，初始化为哑结点

        while pos and pos.next:    # 若当前游标指针后已经没有结点，或者游标指针本身就是空结点，这时后续不可能再出现相同值的结点，因此直接退出处理循环
            # 3.1 若当前结点的值和后驱结点的值不相等，则无需进行删除，直接将pos指向下一个新值的结点
            if pos.val!=pos.next.val: 
                lastpos=pos       # 更新指针
                pos=pos.next
            
            # 3.2 若当前结点的值和后驱结点的值相等，则需要进行删除，这时先找到第一个和当前结点值不相等的结点
            else:
                now=pos.next     
                while now and now.val==pos.val:   # 注意第一个条件，后续可能无法找到与pos不相等的结点
                    now=now.next

                lastpos.next=now      # 将当前结点pos的前驱结点lastpos和第一个和当前结点值不相等的结点now相连接

                # python 无需进行手动的内存释放，因此可以省略释放这些重复结点的内存的过程

                lastpos=lastpos       # 更新指针
                pos=now 
        
        return head.next

                


