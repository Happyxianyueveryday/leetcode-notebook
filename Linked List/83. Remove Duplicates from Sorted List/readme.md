# 83. Remove Duplicates from Sorted List

## 1. 原题和题目分析
原题：

   ![avatar](https://raw.githubusercontent.com/Happyxianyueveryday/Leetcode-Notebook/master/Linked%20List/83.%20Remove%20Duplicates%20from%20Sorted%20List/QQ%E6%88%AA%E5%9B%BE20190222223302.png)

题目分析：
本题可以说是list下最简单的一题，但是仍然要注意可能存在的边缘情况。既然要删除重复的结点，那么使用一个游标指针，对于游标指针指向的每一个位置，均依次找到在指针后的第一个与游标指针指向的结点的值不相同的结点，然后删除在该结点和游标指针之间的结点即可。  
可以直接判断，由于题目对于并不要求删除所有出现重复的结点，而是对于每个结点值，出现多次的保留第一个结点，因此头结点不会被删除，所以可以不考虑使用哑结点。

## 2. 解题算法
本题中使用的解题算法如下所示：
> 1. 创建一个游标指针pos，初始化为链表的头结点head。
> 2. 若pos!=NULL且后继结点pos.next!=NULL，则循环执行下列步骤3到步骤4。
> 3. 若结点pos和pos.next的值不相等，则更新指针pos=pos.next。
> 4. 若结点pos和pos.next的值相等，则首先初始化新的临时指针now=pos.next；然后向后移动指针now，直到now==NULL或者now.val!=pos.val时停止；接着将指针pos和临时指针now指向的结点相连，即pos.next=now，并删除pos和now之间的结点。最后，更新指针pos=now。

## 3. 伪代码实现
> 1. 创建一个游标指针pos，初始化为链表的头结点head。

    pos=head

> 2. 按照上述解题算法描述的步骤2，3，4得到伪代码。

        while pos:
            now=pos.next

            while now and now.val==pos.val:
                now=now.next
            
            pos.next=now    # python无需像C++一样手动释放内存
            pos=now


## 4. 代码实现
C++代码实现请参见83. Remove Duplicates from Sorted List.cpp，python代码实现请参见83. Remove Duplicates from Sorted List.py。

## 5. 边缘情况
> 1. 可能出现重复的结点后面不存在不重复的结点，例如5->2->2->->NULL，这时重复结点2后面均没有出现第一个不重复的结点，因此对于第二部分的解题算法中，向后移动指针now时需要注意now==NULL的情况。
> 2. 原始链表可能本身为空链表。

## 6. 复杂度分析
本题的时间复杂度分析容易出错，假设原始链表总共含有n个结点，回顾解题算法部分的步骤3和4，对于游标指针pos指向的每一个结点，若其后继结点与其不相等，则当前结点是唯一存在的，这时，pos更新为pos=pos.next；否则，其后继结点与其不相等，这时会找到在pos所指向结点后的第一个与pos不相等的结点now，然后令pos=now。  
换言之，每个值出现的第一个结点仅被游标指针pos访问过，其他重复结点仅被游标指针now访问过，因此总的时间复杂度为O(n)。  
由于仅使用了有限且固定个数的游标指针或者临时指针，因此总的空间复杂度为O(1)。
