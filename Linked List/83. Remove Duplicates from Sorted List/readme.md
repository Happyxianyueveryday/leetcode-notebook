# 83. Remove Duplicates from Sorted List

## 1. 原题和题目分析
原题：

![avatar] (https://raw.githubusercontent.com/Happyxianyueveryday/Leetcode-Notebook/master/Linked%20List/83.%20Remove%20Duplicates%20from%20Sorted%20List/QQ%E6%88%AA%E5%9B%BE20190222223302.png)

题目分析：
本题可以说是list下最简单的一题，既然要删除重复的结点，那么使用一个游标指针，对于游标指针指向的每一个位置，均依次找到在指针后的第一个与游标指针指向的结点的值不相同的结点，然后删除在该结点和游标指针之间的结点即可。

## 2. 解题算法
