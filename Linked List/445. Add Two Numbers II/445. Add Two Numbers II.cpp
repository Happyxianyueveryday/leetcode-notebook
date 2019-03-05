/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 由于本题只限制了对链表的反转，而没有限制空间复杂度，因此可以使用额外的一个栈来实现逆序计算，使用栈后进先出特性来进行倒序是栈的一个常见应用
// 本题的基本算法思想是：创建两个栈sta1和sta2，首先对链表1和链表2进行一次遍历，将结点值依次放入sta1和sta2中，最后，依次出栈站定元素，并将数值进行相加
// 在具体的相加部分，直接模仿顺序相加链表的那题即可，如果使用不同的结构容易出现边缘问题，影响解题速度

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 0. 处理特殊情况，即两个链表中至少存在一个为空链表
        if(!l1)
        return l2;
        if(!l2)
        return l1;

        // 1. 遍历链表l1和l2，将结点的值依次放入栈sta1和sta2中
        stack<int> sta1;    // 栈1
        stack<int> sta2;    // 栈2

        ListNode *pos1=l1;
        ListNode *pos2=l2;
        ListNode *res=new ListNode(0);  // 含有哑结点的结果链表头指针

        while(pos1)
        {
            sta1.push(pos1->val);
            pos1=pos1->next;
        }
        while(pos2)
        {
            sta2.push(pos2->val);
            pos2=pos2->next;
        }

        // 2. 从两个栈中同时出栈两个元素，再加上上一次的进位得到计算值并且得到进位
        int ele1=-1;
        int ele2=-1;             // 出栈的两个链表元素
        int carrier=0;           // 来自上一位的进位值

        while(sta1.size()||sta2.size()||carrier)   
        {
            // 2.1 从栈中得到链表1新的结点值
            if(sta1.size())
            {
                ele1=sta1.top();
                sta1.pop();
            }
            else
            ele1=0;

            // 2.2  从栈中得到链表2新的结点值
            if(sta2.size())
            {
                ele2=sta2.top();
                sta2.pop();
            }
            else
            ele2=0;

            // 2.3 计算当前位的结果和进位值，因为需要得到反转的结果链表，因此直接使用头插法，将每次得到的结果插入在头部哑结点后，以得到反转的链表
            int tempres=(ele1+ele2+carrier)%10;
            carrier=(ele1+ele2+carrier)/10;

            ListNode *newnode=new ListNode(tempres);
            newnode->next=res->next;
            res->next=newnode;
        } 

        // 3. 删除结果链表的头结点，返回结果数组
        ListNode *temp=res;
        res=res->next;
        delete temp;

        return res;
    }
};