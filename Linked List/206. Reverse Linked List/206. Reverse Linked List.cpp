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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        
        // 2. 为原始链表增加头部哑结点
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        head=newhead;
        
        // 3. 创建游标指针swap，从反转前的原始链表的第二个结点开始，从原位置删除该结点，将该结点插入到哑结点后
        ListNode *swap=head->next->next;
        ListNode *orihead=head->next;    //原始链表的头结点
        
        while(swap)
        {
            orihead->next=swap->next;
            swap->next=head->next;
            head->next=swap;
            
            swap=orihead->next;
        }
        
        ListNode *temp=head;
        head=head->next;
        delete temp;
        
        return head;
    }
};