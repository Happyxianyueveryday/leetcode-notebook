/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 本题也是链表算法题中较为经典的一个: 使用快速排序进行链表结点的排序，实际上链表结构还是比较适合归并排序而不是快速排序，数组形式的数据更适合快速排序

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 0. 处理递归终止条件: 当待排序的链表为空或者为单结点链表时，无需进行排序，直接返回即可
        if(!head||!head->next)
        return head;

        // 1. 处理一般情况，首先对链表进行partition，选择链表的首元素作为主元，将小于主元的结点从原位置删除并插入到主元之前（即插入到首结点的位置），大于主元的结点的位置保持不动
        ListNode *pivot=head, *pivotprev=NULL;           // 选择链表的首结点为主元元素
        ListNode *now=head->next, *nowprev=head;          // 用于遍历的游标指针now和前驱结点nowprev

        while(now)
        {
            // 1.1 若当前结点的值小于等于主元元素的值，则将该结点从原位置删除，并直接插入到主元元素之前（这里选择插入到链表头部），作为主元结点的前驱结点
            if(now->val<=pivot->val)
            {
                if(head==pivot)     // 第一次插入到主元元素之前的结点就是主元元素的前驱结点
                pivotprev=now; 

                nowprev->next=now->next;
                now->next=head;
                head=now;

                nowprev=nowprev;
                now=nowprev->next;
            }
            else
            {
                nowprev=now;
                now=now->next;
            }
        }

        // 2. 将链表从主元结点为界分为前后两段，前后两段中都不包含主元结点
        ListNode *front=(pivotprev)?head:NULL;    // 若pivotprev==NULL，则说明这时前半部分链表为空链表（即没有元素小于主元）
        ListNode *back=pivot->next;

        if(pivotprev)
        pivotprev->next=NULL;

        pivot->next=NULL;

        // 3. 对分成的前后两段链表进行递归快速排序
        front=sortList(front);
        back=sortList(back);

        // 4. 将前半部分排序结果，主元，后半部分排序结果重新连接起来
        if(front)
        {
            now=front;

            while(now->next)
            now=now->next;

            now->next=pivot;
            pivot->next=back;

            return front;
        }
        else
        {
            pivot->next=back;
            return pivot;
        }
    }
};