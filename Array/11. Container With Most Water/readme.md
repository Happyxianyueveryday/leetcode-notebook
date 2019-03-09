# 11. Container With Most Water

## 1. 题目及题目分析

原题：

![avatar](https://github.com/Happyxianyueveryday/Leetcode-Notebook/blob/master/Array/11.%20Container%20With%20Most%20Water/QQ%E6%88%AA%E5%9B%BE20190309005525.png)

题目分析：
本题和栈tag下的一题接雨水非常相似，但是又有所不同，主要的不同在于本处的数组元素所表示的线本身没有体积，不会影响接水的多少。  
本题属于比较经典的双指针法题目，其分析过程也较为经典，必须深入了解和掌握其分析过程。

## 2. 算法简述
> 1. 创建两个游标指针pos1和pos2；pos1指向数组的首元素，即初始化pos1=0；pos2指向数组的末元素，即初始化pos2=size-1；创建最大盛水量记录变量res=0。
> 2. 当pos1<pos2时，循环进行以下操作：  
>> 2.1. 计算由pos2和pos1指向元素所围成的容器的盛水量tempres，tempres=min(height\[pos1],height\[pos2])\*(pos2-pos1)。
>> 2.2. 若上述计算得到的盛水量大于记录变量res，则更新res: res=tempres。
>> 2.3 

## 3. 双指针移动规则的详细解析


## 4. 实现代码


## 5. 复杂度分析
