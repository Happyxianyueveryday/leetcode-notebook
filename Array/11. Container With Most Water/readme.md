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
>> 2.3. 若height\[pos1]<=height\[pos2]，则向右移动pos1直到第一个大于height\[pos1]的元素为止，将pos1更新为该元素的下标。  
>> 2.4. 若height\[pos1]>height\[pos2]，则向左移动pos2直到第一个大于height\[pos2]的元素为止，将pos2更新为该元素的下标。  
> 3. 退出循环时，res就是最大的盛水量，故直接返回res。  

## 3. 双指针移动规则的详细解析
下面简单解释一下为什么移动双指针时，按照如上的移动规则来进行移动。  
假设指针pos1右侧存在新指针newpos1，指针pos2左侧存在新指针newpos2，则有如下的三种情况：
+ 1. pos1右侧元素小于等于pos1，pos2左侧元素小于等于pos2，即height\[newpos1]<=height\[pos1], height\[newpos2]<=height\[pos2]。这时由newpos1和newpos2围成的容器的盛水量必定小于由pos1和pos2围成的容器的盛水量，故无需进行计算。

![avatar](https://github.com/Happyxianyueveryday/Leetcode-Notebook/blob/master/Array/11.%20Container%20With%20Most%20Water/QQ%E6%88%AA%E5%9B%BE20190309120759.png)

+ 2. pos1右侧元素大于pos1，pos2左侧元素大于pos2，即height\[newpos1]<=height\[pos1], height\[newpos2]<=height\[pos2]。这时由newpos1和newpos2围成的容器的盛水量不一定小于由pos1和pos2围成的容器的盛水量，故需要进行计算以进一步确认。

![avatar](https://github.com/Happyxianyueveryday/Leetcode-Notebook/blob/master/Array/11.%20Container%20With%20Most%20Water/QQ%E6%88%AA%E5%9B%BE20190309120825.png)

+ 3. 若height\[newpos1]和height\[newpos2]中

## 4. 实现代码


## 5. 复杂度分析
