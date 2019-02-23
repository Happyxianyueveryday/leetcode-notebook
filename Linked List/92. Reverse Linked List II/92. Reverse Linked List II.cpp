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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 1. 特殊处理m==n的情况，这时需要反转的链表片段为空链表
        if(m==n)
        return head;

        // 2. 为原始链表加上哑结点，因为头结点可能也会被反转/修改
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        head=newhead;

        // 3. 找出待反转部分链表头节点的前驱结点pos，例如对于链表1->2->3->4->5,m=2,n=4，待反转的部分链表为2->3->4，待反转部分链表的头结点的前驱结点为pos=1
        ListNode *pos=head;
        for(int i=0;i<m-1;i++)
        {
            pos=pos->next;
        }

        // 4. 创建第二个游标指针now，从待反转的部分链表的第二个结点开始遍历直到待反转的部分链表的最后一个结点，对于所访问的每个结点，从所在的位置删除该结点，并将该结点插入到游标指针pos后
        // 例如: 链表1->2->3->4->5,m=2,n=4，其中待反转的部分链表为2->3->4，则从第二个结点3开始，将3插入到pos后得到1->3->2->4->5，将4插入到pos后得到1->4->3->2->1，反转操作完毕
        ListNode *orihead=pos->next;     // 反转操作前待反转部分链表的头结点
        ListNode *now=pos->next->next;   // now游标指针从待反转部分链表的第二个结点开始遍历 // 因为已经排除了m==n，所以才可以连续两次->next

        for(int i=0;i<n-m;i++)
        {
            orihead->next=now->next;
            now->next=pos->next;
            pos->next=now;

            // 更新now指针
            now=orihead->next;
        }

        // 5. 删除头部哑结点
        ListNode *temp=head;
        head=head->next;
        delete temp;

        return head;
    }
};