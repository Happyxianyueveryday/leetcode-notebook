# 21. Merge Two Sorted Lists

  典型的基于二路归并算法的链表题目，二路归并算法我们之前在归并排序中已经深入了解过，对于二路归并的算法必须足够熟悉，能够做到快速实现。
  
  ## 1. 解题算法
  按照归并排序中二路归并的方法进行解答。
  
  > 1. 第一步：创建结果链表res，创建指向结果链表res的指针respos，指向链表1的指针pos1，指向链表2的指针pos2
  > 2. 第二步：循环进行如下步骤：先将pos1指向的结点值和pos2指向的结点值进行比较，较小的结点值加入结果链表，然后移动结果链表指针respos以及pos1和pos1中指向较小的结点的指针，循环上述步骤直到pos1和pos2中存在至一个指针指向空结点为止。
  > 3. 第三步：将pos1和pos2中指向非空结点的指针中剩下的结点全部加入结果链表中。
  
  
  ## 2. 伪代码实现
  伪代码如下：
  
  > 1. 创建包含哑结点的结果链表res，创建指向结果链表res的指针respos，指向链表1的指针pos1，指向链表2的指针pos2
  
     pos1=l1     #链表1游标指针
     pos2=l2     #链表2游标指针
     res=ListNode(0)   #结果链表
     respos=res  #结果链表游标指针
  
  > 2. 先将pos1指向的结点值和pos2指向的结点值进行比较，较小的结点值加入结果链表，然后移动结果链表指针respos以及pos1和pos1中指向较小的结点的指针，循环上述步骤直到pos1和pos2中存在至一个指针指向空结点为止。
  
     while pos1&&pos2:
         if pos1->val<pos2->val:
             respos->next=ListNode(pos1->val)
             pos1=pos1->next
         if pos2.val<pos1.val:
             respos->next=ListNode(pos2->val)
             pos2=pos2->next
         respos=respos->next
   
  > 3. 将pos1和pos2中指向非空结点的指针中剩下的结点全部加入结果链表中。
      
     while pos1:
         respos->next=ListNode(pos1->val)
         pos1=pos1->next
         respos=respos->next
     
     while pos2:
         respos->next=ListNode(pos2->val)
         pos2=pos2->next
         respos=respos->next
  
  ## 3. 易错的边缘情况
  本题中主要存在如下几种容易出现错误的边缘情况，这些边缘情况正是归并排序中所会遇到的边缘情况，对于这些边缘情况，在开始编程实现之前需要做好足够精确的预判。
  
  > 1. 链表l1和l2中存在空链表
  > 2. 链表l1和l2长度不一致
  > 3. 当l1和l2中的一个链表已经完全加入结果链表时，另一个链表中还存在未加入结果链表的结点
  
  
  ## 4. 代码实现
  C++代码实现请参见21. Merge Two Sorted Lists.cpp，python代码实现请参见21. Merge Two Sorted Lists.py。

  ## 5. 复杂度分析
  复杂度与二路归并的复杂度相同，假设两个参与归并的链表的长度分别为m和n，则时间复杂度为O(m+n)，因为所有的两个链表中的每个结点都只被访问一次。
  

