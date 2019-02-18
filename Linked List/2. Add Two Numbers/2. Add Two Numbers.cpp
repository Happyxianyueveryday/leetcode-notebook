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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // 1. 处理存在空链表的特殊情况
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;

        // 2. 设置两个链表指针，从链表头结点开始依次对对应的链表结点相加
        ListNode *pos1=l1;     //链表1指针
        ListNode *pos2=l2;     //链表2指针
        ListNode *res=new ListNode(0);    //结果链表，头部结点使用了哑结点来简化代码结构
        ListNode *respos=res;  //结果链表指针
        int carrier=0;         //进位
        
        while(pos1||pos2||carrier)      
        {
            // 2.1 计算结果
            int temp=((pos1!=NULL)?pos1->val:0)+((pos2!=NULL)?pos2->val:0)+carrier;
            int value=temp%10;        //计算本位置的结果
            carrier=temp/10;          //计算进位
            respos->next=new ListNode(value);

            // 2.2 更新指针
            pos1=(pos1!=NULL)?pos1->next:pos1;
            pos2=(pos2!=NULL)?pos2->next:pos2;
            respos=respos->next;
        }

        // 3. 释放哑结点的空间
        ListNode *temp=res;
        res=res->next;
        delete temp;

        return res;
    }
};

