/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 判断给定的链表是否存在环是链表问题中的高频考点，在各类面试题中是经常出现的常客，除了需要了解如何判断给定的链表中存在环，还需要了解如何查找环的起点，这部分请参见leetcode 链表tag下的另外一道题
// 基本算法思想：
// 0. 处理特殊情况，即给定的链表为空，或者给定的链表中只含有一个结点，这时显然不存在环
// 1. 使用双指针法，设置一个快指针和一个慢指针，快指针初始化为head->next->next，慢指针初始化为head，注意不能同时将快指针和慢指针同时指向head，否则下面地循环条件总是不成立
// 2. 快指针每次移动两步，慢指针每次移动一步，快指针每次移动两步
// 3. 循环进行步骤2，直到快指针指向空结点或者快指针等于慢指针为止
// 4. 若因为快指针指向空结点而退出循环，则给定的链表中不存在环
// 5. 若因为快指针等于慢指针而退出循环，则给定的链表中存在环

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // 1. 处理特殊的两种情况，即原链表为单元素链表或者原链表为空，这两种情况下上述算法不能很好地判断链表中是否存在环，可以试着模拟执行来验证一下
        if(head==NULL||head->next==NULL)
        {
            return false;
        }

        ListNode *slow=head->next;          // 慢指针
        ListNode *fast=head->next->next;    // 快指针
        
        while(fast!=slow&&fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        if(fast==slow)
        return true;
        else
        return false;
    }
};