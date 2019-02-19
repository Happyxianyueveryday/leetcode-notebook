/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // 1. 基本算法实现
        // 处理删除链表倒数第n个结点基本算法是快慢指针法：创建两个初始时指向头结点的指针fast和slow，然后将fast先移动n步，接着slow和fast一直向前移动，直到fast->next==NULL停止，这时slow就指向待删除结点的前向结点
        // 警告: 上述处理一般情况的算法并不适用于处理要删除的结点为头结点的情况，fast移动n步时，n<=m-1，其中m为链表结点的个数，否则后续无法移动fast满足fast->next==NULL
        
        ListNode *fast=head;    //快指针
        ListNode *slow=head;    //慢指针
        
        // 1.1 移动快指针n步
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }

        // 1.2 判断快指针移动n步后是否为空结点，若移动n步后，快指针移动到了空结点，则说明链表的结点总数为n，因此这时要删除的倒数第n个结点就是头结点，删除头结点需要进行特殊处理
        if(fast==NULL)
        {
            ListNode *temp=head;
            head=head->next;      //头结点的后继结点作为新的头结点
            delete temp;          //删除头结点
            return head;
        }

        // 1.3 同时移动快指针和慢指针，直到快指针满足fast->next==NULL，这时慢指针指向待删除结点的前驱结点
        else
        {
            while(fast->next!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
            ListNode *temp=slow->next;
            slow->next=slow->next->next;    //使用两次->next需要极度小心
            delete temp;
            return head;
        }
    }
};