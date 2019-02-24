# 86. Partition List

## 1.  原题和题目分析

原题：

![avatar](https://github.com/Happyxianyueveryday/Leetcode-Notebook/blob/master/Linked%20List/86.%20Partition%20List/QQ%E6%88%AA%E5%9B%BE20190223193203.png)

题目分析：
较为简单的一道题目，题目要求将链表中的元素按照链表中的原始顺序分为两个部分，一部分小于给定的值x，另外一部分大于等于给定的值x。解决思路非常容易得到，创建两个新的链表low和high，然后使用一个游标指针pos遍历原始链表，若访问的结点值小于x，则将其加入链表low中，否则将其加入链表high中。最后，将链表high连接在链表low之后即可。

## 2. 解题算法

> 1. 创建原始链表的一个游标指针pos，初始化为pos=head。创建新的两个链表low和high。
> 2. 若pos!=NULL，则循环执行下列步骤3到5。
> 3. 若pos->val<x，则将当前结点加入到链表low。
> 4. 若pos->val>=x，则将当前结点加入到链表high。
> 5. 更新游标指针pos: pos=pos->next。
> 6. 将链表high连接到链表low之后。
> 7. 返回链表low。

## 3. 伪代码实现
> 1. 创建原始链表的一个游标指针pos，初始化为pos=head。创建新的两个链表low和high。

        pos=head          # 原始链表的游标指针
        low=ListNode(0)   # 给定值的小的结点的链表low(含有哑结点)
        high=ListNode(0)  # 比给定值大的结点的链表high(含有哑结点)

        lowpos=low        # 链表low的游标指针
        highpos=high      # 链表high的游标指针

> 2. 若pos!=NULL，则循环执行下列步骤3到5。
> 3. 若pos->val<x，则将当前结点加入到链表low。
> 4. 若pos->val>=x，则将当前结点加入到链表high。
> 5. 更新游标指针pos: pos=pos->next。

    while pos:
            if pos.val<x:
                lowpos.next=ListNode(pos.val)
                lowpos=lowpos.next
            
            else:
                highpos.next=ListNode(pos.val)
                highpos=highpos.next
            
            pos=pos.next
            
> 6. 将链表high连接到链表low之后。

    lowpos.next=high.next

> 7. 返回链表low。

     return low.next
     
## 4. 代码实现
C++代码实现请参见文件86. Partition List.cpp，python代码实现请参见文件86. Partition List.py。

## 5. 易错的边缘情况
> 1. 原始链表为空链表。
> 2. 回顾第二部分的解题算法部分，当在将链表high连接到链表low之后时，有可能出现链表low为空链表的情况，因此需要特别注意，在初始化链表high和low时需要含有哑结点。


## 6. 复杂度分析
不难分析得出，链表中的每个结点都仅被访问了一次，且除了结果链表外使用的指针数目为确定的有限个，因此时间复杂度为O(n)，空间复杂度为O(1)。

