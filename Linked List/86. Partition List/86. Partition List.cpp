/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//较为简单的一题，创建两个临时链表low和high，然后使用一个游标指针遍历原始链表，若当前链表结点小于值x，则将该链表结点复制一份加入链表low，否则将该链表结点复制一份加入链表high

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 1. 处理原始链表为空的情况
        if(!head)        
        return head;

        // 2. 创建一个游标指针pos以及两个临时链表low和high
        ListNode *pos=head;
        ListNode *low=new ListNode(0);     //含有哑结点
        ListNode *high=new ListNode(0);    //含有哑结点
        ListNode *lowpos=low;
        ListNode *highpos=high;

        // 3. 使用游标指针pos遍历整个原始链表，将小于x的结点加入low，将大于等于x的结点加入high
        while(pos)
        {
            if(pos->val<x)
            {
                lowpos->next=new ListNode(pos->val);
                lowpos=lowpos->next;
            }
            else
            {
                highpos->next=new ListNode(pos->val);
                highpos=highpos->next;
            }

            pos=pos->next;
        }

        // 4. 然后将high链表连接在low后，需要注意特殊情况，low链表可能为空
        if(!high)
        return low;
        else if(!low)
        return high;
        else
        {
            lowpos->next=high->next;
            delete high;          //删除哑结点
            ListNode *temp=low;   
            low=low->next;
            delete temp;          //删除哑结点

            return low;
        }
    }
};