/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 本题的核心思想较为简单：假设链表的结点总数为size，实际上就是找到链表的第k%size个结点，然后将链表从此处断开，前半段链表接到后半段链表之后，更新头结点指针

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 0. 特别判断链表是否为空
        if(!head)
        return head;

        // 1. 首先计算链表的总结点数量
        int size=0;
        ListNode *pos=head;    //链表游标指针
        while(pos)        
        {
            pos=pos->next;
            size+=1;
        }

        // 2. 计算实际应该旋转的结点数量，实际应该旋转的结点数量为k=k%size
        k=k%size;
        
        if(!k)    // 特别处理，若实际应该旋转的结点数量为0，则无需进行旋转
        return head;

        // 3. 需要旋转的结点数量为k%size，则我们使用双指针法找到倒数第k%size+1个结点
        ListNode *fast=head;   //快指针
        ListNode *slow=head;   //慢指针

        for(int i=0;i<k+1;i++)   
        {
            fast=fast->next;   //快指针先移动k+1次
        }

        while(fast)            //然后同时移动快慢指针，直到快指针移动到链表末尾NULL处，这时慢指针就指向倒数第k+1个结点
        {
            fast=fast->next;
            slow=slow->next;
        }

        // 4. 将链表从指针slow处分为前后两段，然后将前半段连接到后半段后
        ListNode *back=slow->next;     //链表后半段
        ListNode *front=head;          //链表前半段
        ListNode *backpos=back;        //链表后半段指针

        slow->next=NULL;              //链表前半段封口（易错点）
        
        //查找后半段的最后一个结点
        while(backpos->next)
        {
            backpos=backpos->next;
        }

        //将前半段连接到后半段后
        backpos->next=front;

        return back;
    }
};