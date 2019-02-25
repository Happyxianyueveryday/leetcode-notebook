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
    void deleteNode(ListNode* node) {
        
        ListNode *now=node;       //游标指针now
        ListNode *lastnow=NULL;   //游标指针now的前驱结点lastnow

        while(now&&now->next)
        {
            now->val=now->next->val;
            lastnow=now;
            now=now->next;
        }
        
        lastnow->next=NULL;

        return;
    }
};