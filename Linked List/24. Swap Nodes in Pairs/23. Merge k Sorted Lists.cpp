/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 基于胜者树的k路归并

#include <limits.h>

using namespace std;

class Solution {
public:
    bool notAllNULL(ListNode *pos[], int size)
    {
        for(int i=0;i<size;i++)
        {
            if(pos[i]!=NULL)
            return true;
        }
        return false;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;

        int size=lists.size();    //参与归并的链表个数或者归并路数
        int count=2*size;         //胜者树的结点数目
        int tree[2*size];         //胜者树
        int lis[size];            //归并指针指向的结点值的数组
        int treeindex[2*size];    //记录胜者树中各个结点对应的元素在lis中的下标
        ListNode *pos[size];      //链表游标指针

        ListNode *res=new ListNode(0);   //结果链表，包含一个哑结点
        ListNode *respos=res;            //结果链表游标指针

        // 1. 初始化结果链表游标指针
        for(int i=0;i<size;i++)
        {
            pos[i]=lists[i];
        }

        // 2. 初始化待归并元素的数组
        for(int i=0;i<size;i++)
        {
            lis[i]=(pos[i]!=NULL)?pos[i]->val:INT_MAX;   //注意是否存在空指针
        }

        // 3. 建立初始的胜者树
        // 3.1 初始化胜者树的叶子结点，胜者树tree的倒数size个元素依次填入数组lis的元素
        for(int i=0;i<size;i++)
        {
            tree[size+i]=lis[i];
            treeindex[size+i]=i;
        }
        // 3.2 倒序更新胜者树的非叶子结点
        for(int i=size-1;i>=1;i--)
        {
            int min=(tree[i*2]<tree[i*2+1])?tree[i*2]:tree[i*2+1];                   //查找两个子节点中的较小值
            int minindex=(tree[i*2]<tree[i*2+1])?treeindex[i*2]:treeindex[i*2+1];    //查找子节点中的较小值在lis中的下标，此处的非叶子结点的下标更新及其容易出错，非叶子结点的值对应的下标由treeindex叶子结点的下标得到
            tree[i]=min;
            treeindex[i]=minindex;
        }

        // 4. 进行迭代，先直接由tree[1]获得最小值，然后更新指针和数组lis，最后对胜者树进行一次调整以保持结构
        while(notAllNULL(pos,size))
        {
            // 4.1 获得最小值并写入结果链表
            respos->next=new ListNode(tree[1]);

            // 4.2 更新链表游标指针
            respos=respos->next;
            pos[treeindex[1]]=pos[treeindex[1]]->next;

            // 4.3 更新数组lis中的值以及胜者树中的叶子结点的对应值
            lis[treeindex[1]]=(pos[treeindex[1]]!=NULL)?pos[treeindex[1]]->val:INT_MAX;
            tree[size+treeindex[1]]=(pos[treeindex[1]]!=NULL)?pos[treeindex[1]]->val:INT_MAX;

            // 4.4 重新调整胜者树以保持性质
            int i=size+treeindex[1];    //发生改变的叶子结点在树中的下标
            while(i!=1)
            {
                i/=2;     //其父结点下标
                tree[i]=(tree[i*2]<tree[i*2+1])?tree[i*2]:tree[i*2+1];                     //更新父结点值为其子结点中的较小值
                treeindex[i]=(tree[i*2]<tree[i*2+1])?treeindex[i*2]:treeindex[i*2+1];      //更新父结点的值在lis中对应的下标
            }
        }

        return res->next;
    }
};