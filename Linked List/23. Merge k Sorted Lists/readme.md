 # 23. Merge k Sorted Lists
 
 ## 1. 预备数据结构基础
 
 ### 1.1 胜者树
 
  胜者树是k路归并问题中经常使用的一种完全二叉树，其标准定义为：每个叶子结点代表一个原始数组中的元素，每个非叶子结点node的值为node的左子结点和右子结点中的较小值（一般定义数值较小者为胜者）。下图就是一个简单的胜者树示例。
  
  ![avatar](https://raw.githubusercontent.com/Happyxianyueveryday/Leetcode-Notebook/master/Linked%20List/23.%20Merge%20k%20Sorted%20Lists/1350310110_2414.jpg)
 
  胜者树主要有两个基本操作：**调整**和**建立**。
  
  #### A. 胜者树的调整
  当一个叶子结点的值改变时时，整个胜者树都需要进行**调整**。调整的具体算法是：
