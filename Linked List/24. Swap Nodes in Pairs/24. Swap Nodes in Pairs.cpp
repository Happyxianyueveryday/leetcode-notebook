/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 非常经典的链表题目，链表元素交换相邻结点是近年来多次在面试或者机试中出现的考题，不仅要理解使用前驱结点作为单个游标指针的思想，还要能够在极短的时间无错实现

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 1. 处理特殊情况：当原始链表为空或者为单结点链表时，无需进行交换，直接返回原链表即可
        if(!head||!head->next)
        return head;

        // 2. 因为链表头部在交换过程中也需要改变，因此首先给原始链表加上哑结点
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        head=newhead;

        // 3. 称两个相邻的结点为一个结点对，初始化一个链表游标指针pos=head，该链表游标指针始终指向某个结点对的前驱结点，通过前驱结点来修改/交换一个结点对中的两个结点的位置
        ListNode *pos=head;

        // 4. 由于pos规定永远指向一个结点对的前驱结点，若pos,pos->next和pos.next.next均存在的话，这时才保证pos后存在一个结点对（两个结点），因此若不满足条件，可以直接退出循环
        while(pos&&pos->next&&pos->next->next)    // pos后存在两个连续结点的充要条件
        {
            // 4.1 重命名结点对中的两个结点
            ListNode *front=pos->next;
            ListNode *back=pos->next->next;

            // 4.2  交换结点对中的两个结点
            pos->next=back;
            front->next=back->next;
            back->next=front;

            // 4.3 更新游标指针pos为下一个结点对的前驱结点，即pos=front
            pos=front;
        }

        // 5. 删除哑结点
        ListNode *temp=head;
        head=head->next;
        delete temp;

        return head;
    }
};