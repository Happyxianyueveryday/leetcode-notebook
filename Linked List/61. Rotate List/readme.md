# 61. Rotate List

  较为简单的题型，需要使用查找链表的倒数第k个结点的快慢双指针法。
  
  ## 0. 原题及题目分析
  原题：  
  ![avatar](https://raw.githubusercontent.com/Happyxianyueveryday/Leetcode-Notebook/master/Linked%20List/61.%20Rotate%20List/QQ%E6%88%AA%E5%9B%BE20190222215848.png)
  
  题目分析：
  从题目给出的若干个示例中，假设链表的元素总数为num，不难看出将给定的链表旋转k步，实际上就是将链表从倒数第k%num个处断开，从而将原始链表分为前后两半，将后半部分的含有倒数k%num个结点的链表接在前半部分链表之前。
  
  ## 1. 基本解题思想
  从上述题目分析中可知，因为要将链表从倒数第k%num个结点处断开，因此我们需要查找倒数第k%num个结点的前驱结点——倒数第(k%num+1)个结点，因此我们将解题过程分为三步：
  > 1. 计算链表的长度num，计算k%num
  > 2. 使用快慢双指针法查找到链表的倒数第k%num+1个结点。
  > 2. 将链表从倒数第k%num个结点切断，分为前后两个部分，将前半部分连接到后半部分后面。
  
  ## 2. 伪代码实现
  假设原始链表头节点为head，旋转结点数为k。  
  
  > 1. 计算链表的长度num
    
        # 1. 首先计算链表的结点总数
        size=0
        pos=head
        while pos:
            pos=pos.next
            size+=1
        
        # 2. 计算需要旋转的结点数目
        k=k%size
  
  > 2. 使用快慢双指针法查找链表的倒数第k+1个结点。
  
        if not k:     # 特殊情况: k==0时相当于没有结点需要进行旋转，此时直接返回原链表
            return head

        # 3. 使用快慢双指针法查找链表的倒数第k%size+1个结点
        fast=head
        slow=head

        for i in range(k+1):
            fast=fast.next
        
        while fast:
            fast=fast.next
            slow=slow.next
        # 此时slow即为倒数的第k%size+1个结点
        
  > 3. 将链表从倒数第k个结点切断，分为前后两个部分，将前半部分连接到后半部分后面。
    
        # 4. 从倒数第k个结点开始，将链表分为前后两个部分
        front=head        # 前半段链表
        back=slow.next    # 后半段链表
        backpos=back      # 后半段链表指针

        slow.next=None    # 前半段链表封口
        
        # 查找后半段链表的末尾结点
        while backpos.next:
            backpos=backpos.next
            
        # 5. 将前半段链表连接到后半段链表后
        backpos.next=front
  
  ## 3. 易错的边缘情况  
  
  > 1. 原始链表为空链表。
  > 2. 旋转次数k大于链表的结点数目。
  
  
  ## 4. 代码实现
  C++代码实现请参见61. Rotate List.cpp，python代码实现请参见61. Rotate List.py。

  ## 5. 复杂度分析
  快慢双指针法查找倒数第k%num+1个结点和重新连接两段链表的时间复杂度均为O(n)，因此总的时间复杂度为O(n)。因为只使用了固定数目的游标指针和临时指针，总的空间复杂度为O(1)。
  


