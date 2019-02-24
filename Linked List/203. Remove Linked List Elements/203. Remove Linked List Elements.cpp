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
    ListNode* removeElements(ListNode* head, int val) {
        // 1. 处理特殊情况
        if(!head)
        return head;

        // 2. 增加头部哑结点
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        head=newhead;

        // 3. 遍历每一个结点，判断是否要进行删除
        ListNode *lastpos=head;
        ListNode *pos=head->next;

        while(pos)
        {
            if(pos->val==val)
            {
                lastpos->next=pos->next;
                lastpos=lastpos;
                ListNode *temp=pos;
                pos=pos->next;
                delete temp;
            }
            else
            {
                lastpos=pos;
                pos=pos->next;
            }
        }

        ListNode *temp=head;
        head=head->next;
        delete temp;

        return head;
    }
};