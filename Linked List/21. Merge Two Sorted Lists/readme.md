# 21. Merge Two Sorted Lists

  典型的基于二路归并算法的链表题目，二路归并算法我们之前在归并排序中已经深入了解过，对于二路归并的算法必须足够熟悉，能够做到快速实现。
  
  ## 1. 基本解题思想
  按照归并排序中二路归并的方法进行解答。
  
  > 1. 第一步
  > 2. 第二步
  > 3. 第三步
  
  
  ## 2. 伪代码实现
  伪代码如下：
  
  > 1. 
  
     fast=head
     slow=head
  
  > 2. 
  
     for i from 0 to n:
         fast=fast->next
   
  > 3. 
      
     if fast==NULL:
         temp=head
         head=head->next
         delete temp
         return head
         
  > 4. 
 
     else:
         while fast->next!=NULL:
             fast=fast->next
             slow=slow->next
         temp=slow->next
         slow=slow->next->next
         delete temp
         return head
  
  ## 3. 易错的边缘情况
  本题中主要存在如下几种容易出现错误的边缘情况，对于这些边缘情况，在开始编程实现之前需要做好足够精确的预判。
  
  > 1. 
  > 2. 
  > 3. 
  
  
  ## 4. 代码实现
  C++代码实现请参见21. Merge Two Sorted Lists.cpp，python代码实现请参见21. Merge Two Sorted Lists.py。

  ## 5. 复杂度分析
  
  

