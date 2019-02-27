# 203. Remove Linked List Elements

## 1. 原题及题目解析
原题：

![avatar](https://github.com/Happyxianyueveryday/Leetcode-Notebook/blob/master/Linked%20List/203.%20Remove%20Linked%20List%20Elements/QQ%E6%88%AA%E5%9B%BE20190227090122.png)

题目解析：
较为基础的题目，考察链表结点最基本的删除操作。由于可能需要删除头结点，因此此处推荐使用哑结点技巧简化代码。具体算法流程如下。
> 0. 向链表增加一个头部哑结点，并更新head指向该哑结点。
> 1. 创建一个游标指针now和游标指针lastnow，初始化now=head.next，lastnow=head，lastnow保持指向结点now的前驱结点。
> 2. 使用游标指针遍历链表中的每一个结点，循环执行下列的步骤3和步骤4，直到now==NULL为止退出循环。
> 3. 若now指向的结点的值等于给定的要删除的值，则通过now的前驱结点删除结点now：lastnow->next=now->next，然后更新now指针，lastnow指针不变：now=lastnow->next。
> 4. 若now指向的结点的值不等于给定的要删除的值，则这时无需删除结点now，直接更新指针now和指针lastnow即可：lastnow=now; now=now->next。
> 5. 返回删除指定结点后的链表结果head->next。

## 2. 解题算法和伪代码实现
> 0. 向链表增加一个头部哑结点，并更新head指向该哑结点。

       newhead=ListNode(0)
       newhead.next=head
       head=newhead
       
> 1. 创建一个游标指针now和游标指针lastnow，初始化now=head.next，lastnow=head，lastnow保持指向结点now的前驱结点。

        lastpos=head      # 游标指针pos的前驱结点
        pos=head.next     # 游标指针pos

> 2. 使用游标指针遍历链表中的每一个结点，循环执行下列的步骤3和步骤4，直到now==NULL为止退出循环。
> 3. 若now指向的结点的值等于给定的要删除的值，则通过now的前驱结点删除结点now：lastnow->next=now->next，然后更新now指针，lastnow指针不变：now=lastnow->next。
> 4. 若now指向的结点的值不等于给定的要删除的值，则这时无需删除结点now，直接更新指针now和指针lastnow即可：lastnow=now; now=now->next。

       while pos:
            if pos.val==val:
                lastpos.next=pos.next
                lastpos=lastpos    # 特别注意两种情况下lastpos游标指针的更新方法
                pos=pos.next
            else:
                lastpos=pos
                pos=pos.next

> 5. 返回删除指定结点后的链表结果head->next。
        
        return head.next

## 3. 易错点辨析
> 1.  在解题前可以做简单的分析，由本题中可能需要删除原始链表的头结点，因此，必须为原始链表首先加上哑结点后，利用哑结点的相关技巧来简化代码。

## 4. 代码实现
C++版本代码实现请参见203. Remove Linked List Elements.cpp，python版本代码实现请参见203. Remove Linked List Elements.py。

## 5. 复杂度分析
不论要删除的元素为何值，都必须使用指针遍历整个链表一遍，因此时间复杂度为O(n)；由于过程中只使用了有限个指针，因此空间复杂度为O(1)。

