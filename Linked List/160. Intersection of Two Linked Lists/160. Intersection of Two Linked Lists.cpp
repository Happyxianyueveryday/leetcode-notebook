/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//本题的思路非常经典，需要特别复习和注意
//解法：
// 1. 创建两个游标指针posa和posb
// 2. 初始化posa=headA，初始化posb=headB，初始化flag=0
// 3. 进行迭代，若posa!=NULL，则更新posa=posa->next，否则更新posa=headB；若posb!=NULL，则更新posb=posb->next，否则更新posb=headA（注意不能同时执行posa=headB和posa=posa->next，否则会出现无法找到相交结点的问题，也很容易从错误样例中发现该问题）
// 4. 若步骤3中满足posa==posb，则退出循环
// 5. 退出循环后，判断pos是否为NULL，若pos==NULL，则说明不存在相交结点，这时直接返回NULL，否则存在相交结点posa，这时返回posa

// 附注：特别注意，可以证明，只需要在一个游标指针到达NULL时，让其重置为另一个链表的头结点重新开始遍历，一定能够达到posa==posb的情况从而退出循环

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 1. 处理特殊情况
        if(!headA||!headB)
        return NULL;

        // 2. 创建两个游标指针posa和posb，分别初始化指向headA和headB的头结点
        ListNode *posa=headA;
        ListNode *posb=headB;

        // 3. 进行第一次迭代过程
        while(posa!=posb)
        {  
            if(posa)
            posa=posa->next;
            else
            posa=headB;
            
            if(posb)
            posb=posb->next;
            else
            posb=headA;
        }
        
        if(posa)
        return posa;
        else
        return NULL;
    }
};