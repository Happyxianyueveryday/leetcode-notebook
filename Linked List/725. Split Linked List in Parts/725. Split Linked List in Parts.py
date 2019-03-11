# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        # 1. 计算每个子链表的长度
        size=0
        now=root
        while now:
            now=now.next
            size+=1

        lis=[size//k for i in range(k)]

        for i in range(size%k):
            lis[i]+=1
        
        # 2. 将各个子链表的链表头结点加入结果列表
        res=[]
        res.append(root)

        print(lis)

        now=root

        for i in range(k-1):
            for n in range(lis[i]):
                now=now.next
            res.append(now)
        
        # 3. 将各个子链表进行截断
        for i in range(k):
            if lis[i]==0:
                res[i]=None
            else:
                now=res[i]
                for m in range(lis[i]-1):
                    now=now.next
                now.next=None
        
        return res
        


        