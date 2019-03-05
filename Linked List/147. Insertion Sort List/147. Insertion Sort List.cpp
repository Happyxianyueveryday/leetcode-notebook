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
    ListNode* insertionSortList(ListNode* head) {
        // 0. 处理特殊情况：若给定的链表为空，或者给定的链表的长度为1，则直接返回
        if(!head||!head->next)
        return head;    

        // 1. 为原始链表增加头部哑结点
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        head=newhead;

        // 2. 创建两个游标指针pos和now，以及这两个游标指针的前驱结点posback和nowback，游标指针pos指向当前准备进行插入的结点
        ListNode *pos=head->next->next;      //pos指针从链表第二个结点开始
        ListNode *posback=head->next;        //pos指针的前驱结点

        while(pos)
        {
            ListNode *now=head->next;        //now指针用于查找第一个大于当前结点pos的结点，即用于查找插入点
            ListNode *nowback=head;

            while(now!=pos)
            {
                if(now->val>pos->val)
                break;
                else
                {
                    nowback=now;
                    now=now->next;
                }
            }

            if(now==pos)                     //若now==pos，这时pos之前的有序部分的结点值均小于结点pos的值，这时pos的位置无需改变
            {
                // 无需改变pos的位置，直接更新游标指针pos和posback
                posback=pos;
                pos=pos->next;
            }
            else                             //否则，pos的位置需要改变，先从原先的位置删除pos，再将该结点插入到正确的位置——now之前，nowback之后
            {
                // 从原位置删除pos
                posback->next=pos->next;

                // 将pos插入到正确位置，也即now之前，nowback之前
                pos->next=nowback->next;
                nowback->next=pos;

                // 更新游标指针pos和posback，因为pos被从原位置删除，因此无需更改posback
                pos=posback->next;
            }
        }

        // 3. 删除链表头部的哑结点
        ListNode *temp=head;
        head=head->next;
        delete temp;

        return head;
    }
};