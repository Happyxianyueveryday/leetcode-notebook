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
>> 3.1. 若nums\[pos1]+nums\[pos2]<target，则将pos1右移1，即pos1+=1。  
>> 3.2. 若nums\[pos1]+nums\[pos2]>target，则将pos1左移1，即pos2-=1。  
>> 3.3. 若nums\[pos1]+nums\[pos2]==target，则直接返回下标。  
> 4. 若执行到退出循环3，则这时不存在满足题意的两个元素。

## 3. 基于哈希表的算法简述和复杂度
基于哈希表的算法描述如下所示：
> 1. 创建一个哈希表dic，需要特别提醒，cpp中的哈希表是unordered_map而不是map，python中的哈希表是dict。
> 2. 遍历整个数组nums，对每个元素nums\[i]循环做如下操作：
>> 2.1. 判断哈希表dic中是否存在键为(target-nums\[i])，若存在，则返回下标i和下标dic\[target-nums\[i]]作为结果。  
>> 2.2. 往哈希表dic中增加键为nums\[i]，值为i的键值对，即dic\[nums\[i]]=i。
> 3. 若循环2结束时仍没有发生返回，则不存在满足题意的两个数组元素。

 + 为什么可以只用一次遍历哈希表而不是两次遍历哈希表？
 + 答： 这是因为加法的交换律，假设a+b=target，且a在数组nums中出现在b之前，这时虽然当遍历到a时，因为b还没有写入哈希表，因此不能发现a+b=target；但是当遍历到b时，这时a已经写入哈希表，因此还是可以发现a+b=target，达到题目的要求。
 
 





