/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 本题所需要使用的思路也较为简单，首先使用一个指针遍历整个链表的第偶数个结点(因为偶数结点是奇数结点的前驱结点)，然后对于每个遇到的奇数结点，删除该奇数结点，并且将该奇数结点插入到头结点之后，最后，返回最终变换后的链表即可

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 1. 处理特殊情况，链表为空或者链表长度为1的情况下，无需进行处理
        if(!head||!head->next)
        return head;

        // 2. 创建一个游标指针now，指向原链表的第二个结点
        ListNode *now=head->next;    //游标指针
        ListNode *insert=head;       //新的遇到的奇数结点应该插入的位置

        // 3. 通过now指针删除now->next并将该结点插入到原始链表的头结点后，然后将该指针向前移动两步
        while(now&&now->next)
        {
            ListNode *swap=now->next;     //待从原位置删除并插入到头结点之后的结点
            
            // 3.1 从原位置删除的结点swap
            now->next=swap->next;         //下面三行指针调整的语句都是按照从等号右侧到左侧的顺序的，需要特别注意

            // 3.2 将结点swap插入到原始链表的头结点之后
            swap->next=insert->next;
            insert->next=swap;

            // 3.3 更新游标指针now和插入位置insert
            now=now->next;
            insert=insert->next;
        }

        return head;
    }
};