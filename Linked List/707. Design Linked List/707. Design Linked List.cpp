
// 链表的数据结构ADT实现，链表基本功
// 但是需要特别说明一点：在就业或者考研时，不论在笔试还是上机考试，都直接使用带有头部哑结点的写法，以简化代码并避免边缘情况，可以有效节省作答该题的时间

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=new ListNode(0);    // 含有哑结点的链表头结点
        size=0;              // 链表中的元素个数
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0||index>=size)
        return -1;
        else
        {
            ListNode *now=head;
            for(int i=0;i<index+1;i++)
            {
                now=now->next;
            }
            return now->val;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *newnode=new ListNode(val);
        newnode->next=head->next;
        head->next=newnode;

        size+=1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *now=head;

        while(now->next)
        {
            now=now->next;
        }

        now->next=new ListNode(val);
        size+=1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<0||index>size)   // 注意使用大于等于，这与上面的查找和下面的删除的边界下标条件不同
        return;

        ListNode *now=head;
        for(int i=0;i<index;i++)
        {
            now=now->next;
        }

        ListNode *newnode=new ListNode(val);
        newnode->next=now->next;
        now->next=newnode;
        size+=1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    // 若不使用链表的头部哑结点，则这里会非常复杂，需要考虑至少三种边缘情况
    void deleteAtIndex(int index) {
        if(index<0||index>=size)
        return;

        ListNode *now=head;
        for(int i=0;i<index;i++)
        {
            now=now->next;
        }

        ListNode *temp=now->next;
        now->next=now->next->next;
        delete temp;
        size-=1;
    }

    private:
    ListNode *head=NULL;    // 链表头结点
    int size;               // 链表长度/链表结点数量
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */