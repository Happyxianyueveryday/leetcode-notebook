/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 非常基础的链表问题，同样使用双指针法进行求解: 
// (1) 创建一个快指针fast和慢指针slow指向链表头结点head
// (2) 将快指针向前移动k步
// (3) 同时循环移动快指针和慢指针一步，直到快指针指向NULL，这时慢指针恰好指向链表的倒数第k个结点，删除慢指针这时所指向的结点即可

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;      // 快指针
        ListNode *slow=head;      // 慢指针
        ListNode *slowprev=NULL;  // 慢指针的前驱结点，因为要删除慢指针所指向的结点，因此需要一个额外的指针指向慢指针的前驱结点

        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }

        while(fast)
        {
            slowprev=slow;
            fast=fast->next;
            slow=slow->next;
        }

        if(slowprev)
        slowprev->next=slow->next;
        else
        head=head->next;
        
        delete slow;  
        
        return head;
    }
};
