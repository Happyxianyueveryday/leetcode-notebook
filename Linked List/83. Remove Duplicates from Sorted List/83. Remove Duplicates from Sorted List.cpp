/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//本题主要综合考察链表结点的查找和删除操作

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 1. 处理链表为空的特殊情况
        if(!head)
        return NULL;

        // 2. 处理一般情况，对于当前游标指针pos指向的结点，从该结点开始向后线性搜索直到发现第一个与pos不相同的结点diffe，然后删除结点diffe和pos之间的链表片段，最后将pos更新为diffe
        ListNode *pos=head;    //链表游标指针：可以确定的是链表的头结点必定不会被删除，无需单独作特殊情况讨论

        while(pos!=NULL)
        {
            // 2.1 移动now指针直到第一个与pos值不相同的结点
            ListNode *now=pos->next;
            while(now&&now->val==pos->val)
            {
                now=now->next;
            }

            // 2.2 连接指针pos指向的结点和指针now指向的结点
            ListNode *temp=pos->next;
            pos->next=now;

            // 2.3 删除原先在指针pos和指针now之间的结点
            while(temp!=now)
            {
                ListNode *temp2=temp;
                temp=temp->next;
                delete temp2;
            }

            // 2.4 更新链表游标指针pos
            pos=now;
        }

        return head;
    }
};