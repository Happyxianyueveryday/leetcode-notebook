/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//查找链表的中间结点是最为经典的链表算法，其查找方法就是：使用快慢指针法，初始化快慢指针为链表头结点，快指针一次走一步，慢指针一次走两步，快指针到达链表末尾时，慢指针就指向了链表中间结点

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;

        while(fast&&fast->next)        
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        return slow;
    }
};