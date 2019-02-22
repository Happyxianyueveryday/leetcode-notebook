# 19. Remove Nth Node From End of List

  本题的任务虽然是删除链表的倒数第n个结点，实际上代表着一类题型，即如何访问链表的倒数第n个结点的问题。
  
  ## 0. 原题及题目分析
  原题：  
  ![avatar](https://raw.githubusercontent.com/Happyxianyueveryday/Leetcode-Notebook/master/Linked%20List/19.%20Remove%20Nth%20Node%20From%20End%20of%20List/QQ%E6%88%AA%E5%9B%BE20190222212440.png)
  
  题目分析：  
  要删除一个链表的某个结点，只需要找到该待删除结点的前驱结点，然后即可通过前驱结点删除该结点。本题要删除链表的倒数第n个结点，因此需要查找链表的倒数第n+1个结点，找到该前驱结点后，即可删除目标结点。 
  
  ## 1. 解题算法
  使用快慢双指针法。  
  
  ![avatar](https://raw.githubusercontent.com/Happyxianyueveryday/Leetcode-Notebook/master/Linked%20List/19.%20Remove%20Nth%20Node%20From%20End%20of%20List/QQ%E6%88%AA%E5%9B%BE20190222215358.png)
  
  对应的文字表述如下。
  > 1. 第一步，创建两个指针，即指向链表头结点的快指针fast，以及慢指针slow
  > 2. 第二步，快指针fast向前移动n步，慢指针保持不动
  > 3. 第三步，若第二步完成后的快指针fast==NULL，这时说明链表总共有n个结点（因为fast移动了n步），待删除的结点就是头结点，这时特殊处理，删除头结点；若fast!=NULL，这时同时移动快指针fast和慢指针slow，直到fast->next==NULL时停止，这时的慢指针slow就指向待删除结点的前驱结点，通过该前驱结点删除待删除结点即可。
  
  
  ## 2. 伪代码实现
  伪代码如下：
  
  > 1. 创建快指针fast，慢指针slow指向头节点head
  
     fast=head
     slow=head
  
  > 2. 将快指针fast移动n步
  
     for i from 0 to n:
         fast=fast->next
   
  > 3. 判断fast指针是否为空，若为空，则说明要删除的结点是头节点，这时进行特殊处理
      
     if fast==NULL:
         temp=head
         head=head->next
         delete temp
         return head
         
  > 4. 若fast指针不为空，则要删除的结点不是头结点，这时同时移动快指针fast和慢指针slow，直到fast->next==NULL为止，这时慢指针slow就指向待删除结点的前驱结点，通过该前驱结点删除掉待删除结点
 
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
  
  > 1. 待删除的结点为链表的头结点
  > 2. 待删除的结点为链表的尾结点
  > 3. 本题中的倒数第n个结点中的n必然合法，若没有该说明，可能需要进一步考虑参数n的合法性
  
  
  ## 4. 代码实现
  C++代码实现请参见19. Remove Nth Node From End of List.cpp，python代码实现请参见19. Remove Nth Node From End of List.py。

  ## 5. 复杂度分析
  假设链表的长度（结点数目为m）；快指针首先移动n步，时间消耗为n；然后快慢指针同时移动直到快指针到最后一个结点，时间消耗为m-1-n；两者相加即为m-1，因此时间复杂度为O(m)。由于只用了固定个数的游标指针和临时指针，因此空间复杂度为O(1)。
  
