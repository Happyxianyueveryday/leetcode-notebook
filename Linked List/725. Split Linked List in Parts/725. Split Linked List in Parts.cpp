/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 较为简单的题目，关键在于掌握如何分配各个划分的子链表中的结点个数，使得这些链表的结点个数不相差1

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // 0. 计算给定的链表的结点个数
        ListNode *now=root;
        int size=0;
        while(now)
        {
            now=now->next;
            size+=1;
        }

        // 1. 计算k个划分出的各个子链表中的结点个数
        // 具体的计算方法是：创建一个含有k个元素的数组，首先将每个元素初始化为size/k，然后将前size%k个元素的值加上1
        int lis[k];
        for(int i=0;i<k;i++)
        {
            lis[i]=size/k;
        }

        for(int i=0;i<size%k;i++)
        {
            lis[i]+=1;
        }
        
        // 2. 进行链表分割，将每一段链表的头结点先加入结果数组
        vector<ListNode *> res;       // 划分的结果数组
        ListNode *splithead=root;     // 划分出的子链表的头结点
        now=root;                     // 游标指针now

        res.push_back(root);  

        for(int i=0;i<k-1;i++)
        {
            for(int l=0;l<lis[i];l++)
            {
                now=now->next;
            }
            res.push_back(now);
        }

        // 3. 将结果中的每一个子链表进行封口
        for(int i=0;i<k;i++)
        {
            now=res[i];

            if(lis[i]==0)
            res[i]=NULL;
            else
            {
                for(int l=0;l<lis[i]-1;l++)
                {
                    now=now->next;
                }
                now->next=NULL;
            }
        }

        return res;
    }
};