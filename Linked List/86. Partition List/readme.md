# 86. Partition List

## 1.  原题和题目分析

原题：

![avatar](https://github.com/Happyxianyueveryday/Leetcode-Notebook/blob/master/Linked%20List/86.%20Partition%20List/QQ%E6%88%AA%E5%9B%BE20190223193203.png)

题目分析：
较为简单的一道题目，题目要求将链表中的元素按照链表中的原始顺序分为两个部分，一部分小于给定的值x，另外一部分大于等于给定的值x。解决思路非常容易得到，创建两个新的链表low和high，然后使用一个游标指针pos遍历原始链表，若访问的结点值小于x，则将其加入链表low中，否则将其加入链表high中。最后，将链表high连接在链表low之后即可。

## 2. 解题算法

> 1. 创建原始链表的一个游标指针pos。创建新的两个链表low和high。
> 2. 若pos!=NULL，则循环执行下列步骤。
> 3. 

