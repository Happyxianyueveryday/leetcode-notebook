/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// sortList: 对数组进行归并排序

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 0. 处理递归终止情况，当链表为空或者链表中仅有一个结点，这时可以直接返回，无需排序
        if(!head||!head->next)
        return head;

        // 1. 处理一般情况
        // 1.1 首先通过快慢双指针法查找到链表的中间结点
        ListNode *fast=head, *slow=head, *slowprev=head;

        while(fast&&fast->next)
        {
            slowprev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        // 1.2 从中间结点开始，将链表划分为前后两段
        ListNode *front=head;   // 前半部分链表
        ListNode *back=slow;    // 后半部分链表
        slowprev->next=NULL;    // 分离前半部分和后半部分链表

        // 1.3 递归地排序前半部分链表和后半部分链表
        front=sortList(front);
        back=sortList(back);

        // 1.4 对已经分别排序完成的前半部分链表和后半部分链表进行合并(merge)操作
        ListNode *res=new ListNode(0);                   // 结果链表(包含头部哑结点)
        ListNode *now1=front, *now2=back, *resnow=res;   // 用于归并的游标指针

        while(now1&&now2)
        {
            if(now1->val<now2->val)
            {
                resnow->next=now1;                       // 注意应该使用原始链表的结点作为结果链表的结点，而非创建新的深拷贝结点
                now1=now1->next;
                resnow=resnow->next;      
            }
            else
            {
                resnow->next=now2;
                now2=now2->next;
                resnow=resnow->next;
            }
        }

        while(now1)
        {
            resnow->next=now1;
            now1=now1->next;
            resnow=resnow->next;
        }

        while(now2)
        {
            resnow->next=now2;
            now2=now2->next;
            resnow=resnow->next;
        }

        // 1.5 删除结果链表的头部哑结点
        ListNode *temp=res;
        res=res->next;
        delete temp; 

        return res; 
    }
};