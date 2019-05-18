/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 链表反转是最经典的链表算法题，链表反转有两种方法，头部插入法和原地反转法，这两种算法都要求能够良好地掌握

// 1. 头部插入法：从原链表的第二个结点开始，不断将结点从原位置删除并插入到链表头，例如1->2->3->4->5的反转过程为:2->1->3->4->5, 3->2->1->4->5, ... , 5->4->3->5->1

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 0. 原链表为空或者仅含一个结点时无需反转
        if(!head||!head->next)
        return head;

        // 1. 正式进行反转过程，从原链表的第二个结点开始，不断从原位置删除该结点，并将该结点插入到链表头部
        ListNode *now=head->next;    // 遍历链表的游标指针
        ListNode *nowprev=head;      // 游标指针now的前驱结点

        while(now)
        {
            // 1.1 从原位置删除结点
            nowprev->next=now->next;

            // 1.2 将结点插入到链表头
            now->next=head;
            head=now;

            // 1.3 更新游标指针now和其前驱结点nowprev
            nowprev=nowprev;
            now=nowprev->next;
        }

        return head;
    }
};


// 2. 原地反转法: 依次使用一个游标指针访问链表中的每一个结点，并将当前结点的next指针反转，指向其前驱结点

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 0. 原链表为空或者仅含一个结点时无需反转
        if(!head||!head->next)
        return head;

        // 1. 依次使用一个游标指针访问链表中的每一个结点，并将当前结点的next指针反转，指向其前驱结点
        ListNode *now=head;           // 用于遍历链表的游标指针
        ListNode *nowprev=NULL;       // 游标指针now的前驱结点

        while(now)
        {
            // 1.1 反转当前结点的next指针
            ListNode *temp=now->next;     // 先保存当前结点now的后继结点
            now->next=nowprev;            // 反转当前结点的next指针
            
            // 1.2 更新游标指针now和nowprev，更新链表头结点
            nowprev=now;
            now=temp;
        }

        head=nowprev;    // 当遍历结束后，now指向NULL，则nowprev就指向原链表的最后一个结点，也就是反转后的链表的首结点
        
        return head;
    }
}; 
