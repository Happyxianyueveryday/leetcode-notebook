/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 本题是非典型的链表题，但是算法思路均是基于一些比较基础的链表题中所使用的方法
// 本题的算法设计思路如下：
// 1. 对于输入的链表，找到链表的中间结点
// 2. 将链表从中间结点分为两段，前半段的链表进行封口，后半段的链表结点依次加入一个栈中（从而实现倒序访问链表后半段的结点）
// 3. 创建一个游标指针now，使用该指针遍历前半段的每个链表结点，游标指针now每访问一个链表结点，就从栈中出栈一个链表结点，将该结点插入在指针now所指向的结点之后
// 4. 重复步骤3，直到栈为空为止，这时直接返回修改后的链表即可
// 附注： 由于本题中无需修改原始链表的头结点，因此可以无需使用头部哑结点的技巧

class Solution {
public:
    void reorderList(ListNode* head) {

        // 0. 处理特殊情况，即给定的链表为空，或者链表只有一个元素
        if(!head||!head->next)
        return;

        // 1. 先使用快慢双指针法查找链表的中间结点
        ListNode *fast=head;    // 快指针
        ListNode *slow=head;    // 慢指针

        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        // 2. 将链表从中间结点分为两段，将前半段封口，将后半段的结点依次入栈
        ListNode *back=slow->next;    // 后半段链表
        ListNode *front=head;         // 前半段链表

        slow->next=NULL;              // 前半段链表封口
        
        // 后半段链表入栈
        stack<ListNode *> sta;        
        ListNode *now=back;
        while(now)
        {
            sta.push(now);
            now=now->next;
        }
        
        // 3. 重新设置游标指针now，该指针依次遍历前半段链表的每一个结点，每次访问一个新的结点，从栈顶取出一个后半段链表的结点，并将其插入在now结点后
        now=head;
        while(sta.size())
        {
            // 取出栈顶结点
            ListNode *temp=sta.top();
            sta.pop();

            // 插入出栈的后半段链表的结点
            temp->next=now->next;
            now->next=temp;

            // 更新游标指针
            now=temp->next;
        }
    }
};