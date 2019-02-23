# 82. Remove Duplicates from Sorted List II

## 1. 基本算法思想
由于按照题目要求，需要删除掉所有出现重复的值的结点，因此可能需要删除头结点，我们需要使用哑结点作为头结点。并且需要保存所使用的游标指针的前驱结点，具体算法步骤简述如下。

> 1. 向原始链表的头结点之前插入一个哑结点，记新的头结点为head。
> 2. 创建一个游标指针pos，初始化为head->next，该游标指针规定指向链表中第一个等于某个值的结点；创建另一个游标指针lastpos，初始化为head，规定该结点必须保持是pos的前驱结点。（为了删除重复值出现的片段，首先应当查找某个固定的重复值出现的第一个结点pos的前驱结点）。
> 3. 若pos和pos.next均不为空结点，则循环执行下列步骤a到c（若pos.next为空，则不可能出现与pos相等的重复值结点，因此作为判断条件）：
>> a. pos和pos.next的值若不相等，则说明pos后面没有与pos相等的结点；这时更新游标指针：lastpos=pos, pos=pos.next。  
>> b. pos和pos.next的值若相等，则说明pos后存在与pos相等的重复结点；这时首先查找pos后第一个与pos不相等的结点now（也有可能该结点不存在，now=NULL)，然后连接lastpos和now，即lastpos.next=now，并删除中间的结点；最后更新指针：lastpos保持不变，pos=now。
> 4. 返回处理后的链表头结点head.next。

## 2. 伪代码实现
> 1. 向原始链表的头结点之前插入一个哑结点，记新的头结点为head。

    # 2. 为原始链表加上头部哑结点
    newhead=ListNode(0)
    newhead.next=head
    head=newhead
    
> 2. 创建一个游标指针pos，初始化为head->next，该游标指针规定指向链表中第一个等于某个值的结点；创建另一个游标指针lastpos，初始化为head，规定该结点必须保持是pos的前驱结点。（为了删除重复值出现的片段，首先应当查找某个固定的重复值出现的第一个结点pos的前驱结点）。

    # 3. 创建链表游标指针
    pos=head.next     # 初始化链表游标指针为首结点，该游标指针只会指向相同值的结点中的第一个结点
    lastpos=head      # 链表游标指针pos的前驱结点，初始化为哑结点

> 3. 若pos和pos.next均不为空结点，则循环执行下列步骤a到c（若pos.next为空，则不可能出现与pos相等的重复值结点，因此作为判断条件）：
>> a. pos和pos.next的值若不相等，则说明pos后面没有与pos相等的结点；这时更新游标指针：lastpos=pos, pos=pos.next。  
>> b. pos和pos.next的值若相等，则说明pos后存在与pos相等的重复结点；这时首先查找pos后第一个与pos不相等的结点now（也有可能该结点不存在，now=NULL)，然后连接lastpos和now，即lastpos.next=now，并删除中间的结点；最后更新指针：lastpos保持不变，pos=now。

    while pos and pos.next:    # 若当前游标指针后已经没有结点，或者游标指针本身就是空结点，这时后续不可能再出现相同值的结点，因此直接退出处理循环
        # 3.1 若当前结点的值和后驱结点的值不相等，则无需进行删除，直接将pos指向下一个新值的结点
        if pos.val!=pos.next.val: 
            lastpos=pos       # 更新指针
            pos=pos.next
            
        # 3.2 若当前结点的值和后驱结点的值相等，则需要进行删除，这时先找到第一个和当前结点值不相等的结点
        else:
            now=pos.next     
            while now and now.val==pos.val:   # 注意第一个条件，后续可能无法找到与pos不相等的结点
                now=now.next

            lastpos.next=now      # 将当前结点pos的前驱结点lastpos和第一个和当前结点值不相等的结点now相连接

            # python 无需进行手动的内存释放，因此可以省略释放这些重复结点的内存的过程

            lastpos=lastpos       # 更新指针
            pos=now 
            
> 4. 返回处理后的链表头结点head.next。

     return head.next

## 3. 代码实现
C++实现代码请参见82. Remove Duplicates from Sorted List II.cpp，python实现代码请参见82. Remove Duplicates from Sorted List II.py。


## 4. 易错的边缘情况

? 1. 原始链表为空链表。
> 2. 原始链表中不存在唯一存在的结点，即每个结点都存在重复结点，这时需要删除头结点，最终得到的结果为空链表。


## 5. 算法复杂度分析
本题和 Remove Duplicates from Sorted List类似，只是在那一题中，对于出现重复值的结点，我们要求保留第一个结点，而在本题中，我们要求删除所有出现重复的常见数值。
因此本题的时间复杂度和空间复杂度均和Remove Duplicates from Sorted List一题类似，时间复杂度为O(n)，空间复杂度为O(1)。

