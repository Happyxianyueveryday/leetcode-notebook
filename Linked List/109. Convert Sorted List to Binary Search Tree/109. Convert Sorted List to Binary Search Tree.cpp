/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//较为简单的一道题目：可以直接使用递归求解，递归求解的思路：对于给定的链表，首先先查找到链表的中间结点，然后以中间结点作为根节点，左子树由中间结点之前的链表递归生成，右子树由中间结点之后的链表递归生成

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 1. 处理特殊的空结点情况
        if(!head)             
        return NULL;

        // 2. 处理特殊的叶子结点的情况
        if(head&&!head->next)
        {
            TreeNode *root=new TreeNode(head->val);
            return root;
        }

        // 3. 处理一般链表的情况
        // 3.1 使用快慢双指针法查找到链表的中间结点
        ListNode *fast=head;        //快指针
        ListNode *slow=head;        //慢指针
        ListNode *lastslow=NULL;    //慢指针的前驱结点

        while(fast&&fast->next)
        {
            lastslow=slow;

            fast=fast->next->next;
            slow=slow->next;
        }

        // 3.2 创建中间结点的根节点
        TreeNode *root=new TreeNode(slow->val);

        lastslow->next=NULL;   //断开前半部分链表

        // 3.3 递归生成左子树和右子树
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        
        return root;
    }
};