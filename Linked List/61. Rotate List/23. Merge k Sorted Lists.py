# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 使用胜者树的版本已经在C++版本中实现过，请参见本文件夹下的cpp代码文件，本处使用胜者树重新进行实现

class Solution:
    def allvalue(self,iterable):
        for k in iterable:
            if k:
                return True
        return False

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        
        # 1. 创建k个链表的游标指针，创建结果链表
        k=len(lists)      # 链表数目，即k路归并的路数k
        pos=[lists[i] for i in range(k)]    # k个链表的游标指针
        lis=[0 for i in range(k)]          # k个链表的游标指针指向的结点的值的数组
        
        res=ListNode(0)  # 结果链表
        respos=res       # 结果链表指针
        
        # 2. 创建胜者树
        tree=[0 for i in range(2*k)]        # 若为k路归并，则胜者树的结点数目为2*k
        treeindex=[0 for i in range(2*k)]   # 胜者树中的每个结点的值在数组lis中的下标
        
        # 3. 初始化数组lis
        for i in range(k):
            lis[i]=pos[i].val if pos[i] else float('inf')
        
        # 4. 建树过程
        # 4.1 胜者树tree的后k个值即为叶子结点，将其依次初始化为lis数组的值，同时同步初始化对应的下标数组treeindex
        for i in range(k):
            tree[k+i]=lis[i]
            treeindex[k+i]=i

        # 4.2 胜者树tree的前k个值即为非叶子结点，我们将其进行倒序初始化
        for i in range(k-1,-1,-1):
            tree[i]=min(tree[i*2],tree[i*2+1])    
            treeindex[i]=treeindex[i*2 if tree[i*2]<tree[i*2+1] else i*2+1]
        
        # print("tree = ", tree)
        # print("treeindex = ",treeindex)

        # 5. 归并过程
        while(self.allvalue(pos)):

            # 5.1 提取胜者树的根结点的值加入结果链表中
            respos.next=ListNode(tree[1])
            
            # 5.2 更新各项指针
            respos=respos.next                          # 更新结果链表指针
            pos[treeindex[1]]=pos[treeindex[1]].next    # 更新加入结果链表的结点对应的归并指针，通过treeindex数组找到对应的指针的下标
            
            # 5.3 更新归并指针结点值数组lis与胜者树tree的叶子结点
            tree[treeindex[1]+k]=pos[treeindex[1]].val if pos[treeindex[1]] else float('inf')
            lis[treeindex[1]]=pos[treeindex[1]].val if pos[treeindex[1]] else float('inf')

            # 5.4 重新调整胜者树以保持其性质
            i=treeindex[1]+k
            while i!=1:
                i=i//2
                tree[i]=min(tree[2*i],tree[2*i+1])
                treeindex[i]=treeindex[i*2 if tree[i*2]<tree[i*2+1] else i*2+1]

        return res.next