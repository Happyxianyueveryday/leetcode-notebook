/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 判断一个链表是否为回文链表是链表中一个较为经典的题目，在要求使用O(n)的时间复杂度和O(1)的空间复杂度的情况下，只需要找到链表的中间结点，将后半部分的链表反转，再和前半部分链表结点进行依次比较
// 如果不严格限定空间复杂度为O(1)，这时只需要遍历一遍结点，将后半部分结点入栈，在依次出栈和前半部分结点比较即可，但是要求O(1)的空间复杂度的基础上，就必须改变原链表，将原链表的后半部分反转

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 0. 处理特殊情况
        if(!head||!head->next)
        return true;

        // 1. 首先使用双指针法查找链表的中间结点
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *slowback=NULL;   // slow指针指向结点的前驱结点
        
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slowback=slow;
            slow=slow->next;
        }

        // 2. 然后从中间结点slow开始，将整个链表分为两半
        slowback->next=NULL;
        ListNode *front=head;
        ListNode *back=slow;

        // 3. 将后半部分链表反转
        ListNode *now=back->next;
        ListNode *nowback=back;        // now指针的前驱结点
        while(now)
        {
            nowback->next=now->next;
            now->next=back;
            back=now;
            now=nowback->next;
        }

        // 4. 设置两个指针pos1和pos2，分别指向前半段链表的头结点和后半段链表的头结点，然后依次比较两个指针所指向的值是否相等
        ListNode *pos1=front;
        ListNode *pos2=back;

        while(pos1&&pos2)
        {
            if(pos1->val!=pos2->val)
            return false;
            else
            {
                pos1=pos1->next;
                pos2=pos2->next;
            }
        }

        return true;
    }
};