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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // 1. 优先处理特殊情况，即l1和l2中存在一个链表为空的情况
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;

        // 2. 使用双指针进行和归并排序中类似的归并操作
        ListNode *pos1=l1;      //链表1游标指针
        ListNode *pos2=l2;      //链表2游标指针
        ListNode *res=new ListNode(0);    //结果链表，同样使用了哑结点
        ListNode *respos=res;             //结果链表指针

        while(l1!=NULL&&l2!=NULL)
        {
            respos->next=new ListNode((l1->val<l2->val)?l1->val:l2->val);

            if(l1->val<l2->val)
            l1=l1->next;
            else
            l2=l2->next;
            respos=respos->next;
        }

        // 3. 处理两个链表中的剩下部分
        while(l1!=NULL)
        {
            respos->next=new ListNode(l1->val);

            l1=l1->next;
            respos=respos->next;
        }

        while(l2!=NULL)
        {
            respos->next=new ListNode(l2->val);

            l2=l2->next;
            respos=respos->next;
        }

        // 3. 删除结果链表的哑结点，返回最终结果
        ListNode *temp=res;
        res=res->next;
        delete temp;

        return res;
    }
};