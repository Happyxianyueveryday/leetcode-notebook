/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//本题中要求删除掉所有出现重复的值对应的结点，因此需要特别注意一个边缘问题——有可能整个链表删除后变成空链表

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 0. 处理特殊情况
        if(!head||!head->next)
        return head;

        // 1. 因为可能需要删除原链表的头结点，因此直接先考虑给原链表头部加上哑结点
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        head=newhead;

        // 1. 创建链表游标指针
        ListNode *pos=head->next;  //链表游标指针pos
        ListNode *lastpos=head;    //记录链表游标指针的pos上一个取值
        
        // 2. 使用链表游标指针遍历整个链表，直到到达链表的最后一个结点
        while(pos!=NULL&&pos->next!=NULL)     //游标指针pos到最后一个结点就可以停止迭代过程
        {
            // 2.1 不存在相同值的结点，则直接更新指针进行下一轮迭代
            if(pos->next->val!=pos->val)   
            {
                lastpos=pos;
                pos=pos->next;
                continue;
            }
            // 2.2  存在相同值的结点，则进行删除处理
            else
            {
                // 2.2.1 先查找pos后的第一个不等于pos的值的结点now
                ListNode *now=pos->next;
                while(now&&now->val==pos->val)
                {
                    now=now->next;
                }

                //2.2.2 释放待删除结点的内存
                ListNode *temp=lastpos->next;
                while(temp!=now)
                {
                    ListNode *temp2=temp;
                    temp=temp->next;
                    delete temp2;
                }

                // 2.2.3 将lastpos和结点now相连
                lastpos->next=now;

                // 2.2.4 更新指针pos和lastpos
                lastpos=lastpos;    //lastpos不变
                pos=now;
            }
        }

        ListNode *temp=head;
        head=head->next;
        delete temp;

        return head;
    }
};