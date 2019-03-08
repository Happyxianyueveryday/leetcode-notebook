# 1. Two Sum

## 1. 原题及题目分析

原题：

  ![avatar](https://github.com/Happyxianyueveryday/Leetcode-Notebook/blob/master/Array/1.%20Two%20Sum/QQ%E6%88%AA%E5%9B%BE20190309005533.png)

题目分析：
Two Sum作为leetcode编号为1的，最经典的一题，需要至少熟练掌握双指针和哈希表两种解法，并能够熟练地快速实现代码。

## 2. 基于双指针的算法描述和复杂度
基于双指针的算法描述如下所示：
> 1. 将原数组nums进行快速排序。
> 2. 创建两个游标指针pos1和pos2，初始化pos1为首元素下标:pos1=0，初始化pos2为末元素下标size-1。
> 3. 当pos1<pos2时，循环进行以下步骤：
>> 3.1. 若nums\[pos1]+nums\[pos2]<target，则将pos1右移1，即pos1+=1  
>> 3.2. 若nums\[pos1]+nums\[pos2]>target，则将pos1左移1，即pos2-=1  
>> 3.3. 若nums\[pos1]+nums\[pos2]==target，则直接返回下标  
> 4. 若执行到退出循环3，则这时不存在满足题意的两个元素

## 3. 基于哈希表的算法简述和复杂度






