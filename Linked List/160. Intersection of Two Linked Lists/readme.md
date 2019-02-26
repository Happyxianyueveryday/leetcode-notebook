# 160. Intersection of Two Linked Lists

## 1. 原题和题目分析

原题：
![avatar](https://raw.githubusercontent.com/Happyxianyueveryday/Leetcode-Notebook/master/Linked%20List/160.%20Intersection%20of%20Two%20Linked%20Lists/QQ%E6%88%AA%E5%9B%BE20190224115347.png)

题目分析：
本题为链表的常见考点题，虽然题目的难度标定为easy，但是所使用的解题算法非常经典，必须要能够熟练掌握。解题的算法思路如下所示。
> 1. 创建两个游标指针pos1和pos2，分别指向链表headA和链表headB。
> 2. 若pos1!=pos2，则循环执行下面的步骤3和步骤4，
> 3. 若pos1!=NULL，则将pos1向前移动一步，即: pos1=pos1->next；否则，重置pos1指针指向链表2，即pos1=headB。 
> 4. 若pos2!=NULL，则将pos2向前移动一步，即: pos2=pos2->next；否则，重置pos2指针指向链表1，即pos2=headA。 
> 5. 当违反循环条件退出循环后，若pos1==NULL，则说明两个链表不存在交点，直接返回NULL；若pos!=NULL，则两个链表存在交点，交点就是结点pos1（或者pos2，因为pos1==pos2）。
> 附注：需要特别注意，将指针pos1或者pos2向前移动一步，或者将其重置为另一个链表的头结点，两种操作只能进行其中一步，  。

例如，使用上述算法思路查找链表交点的一个示例如下图所示。

![avatar](https://github.com/Happyxianyueveryday/Leetcode-Notebook/blob/master/Linked%20List/160.%20Intersection%20of%20Two%20Linked%20Lists/QQ%E5%9B%BE%E7%89%8720190224115214.jpg)

## 2. 解题算法和伪代码实现

## 3. 代码实现

## 4. 易错点警示

## 5. 复杂度分析







