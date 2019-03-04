
# 链表的数据结构ADT实现，链表基本功
# 但是需要特别说明一点：在就业或者考研时，不论在笔试还是上机考试，都直接使用带有头部哑结点的写法，以简化代码并避免边缘情况，可以有效节省作答该题的时间
# 另外不论还是删除还是插入，关键点都在查找插入点和删除点的前驱结点


class MyLinkedList(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head=ListNode(0)   # 含有哑结点的头结点
        self.size=0             # 链表结点数量
        

    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        :type index: int
        :rtype: int
        """
        if index<0 or index>=self.size:
            return -1
        else:
            now=self.head
            
            for i in range(index+1):
                now=now.next
            
            return now.val
        

    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        :type val: int
        :rtype: None
        """
        newnode=ListNode(val)
        newnode.next=self.head.next
        self.head.next=newnode
        self.size+=1

        return
        

    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        :type val: int
        :rtype: None
        """
        now=self.head
        
        while now.next:
            now=now.next
        
        newnode=ListNode(val)
        now.next=newnode
        self.size+=1

        return
        
        

    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        :type index: int
        :type val: int
        :rtype: None
        """
        if index<0 or index>self.size:
            return
         
        now=self.head
        
        for i in range(index):
            now=now.next
        
        newnode=ListNode(val)
        newnode.next=now.next
        now.next=newnode
        self.size+=1

        return

    def deleteAtIndex(self, index):
        """
        Delete the index-th node in the linked list, if the index is valid.
        :type index: int
        :rtype: None
        """
        if index<0 or index>=self.size:
            return
        
        now=self.head
        
        for i in range(index):
            now=now.next
        
        now.next=now.next.next
        self.size-=1

        return


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)