 # 109. Convert Sorted List to Binary Search Tree
 
 ## 1. 原题和题目分析
 原题：
 ![avatar] (https://raw.githubusercontent.com/Happyxianyueveryday/Leetcode-Notebook/master/Linked%20List/109.%20Convert%20Sorted%20List%20to%20Binary%20Search%20Tree/QQ%E6%88%AA%E5%9B%BE20190226232849.png)
 
 本题在树的tag下同样会遇到，将有序链表转化为高度平衡的二叉树的算法是固定的，推荐熟练地记忆下此算法，使用如下的递归方法进行转换：
 > 1. 使用快慢双指针法查找输入链表的中间结点，并将中间结点作为该树的根结点。
 > 2. 将输入链表从中间结点分为两部分，从第一个结点到中间结点（但不包括中间结点）为前半部分，从中间结点（但不包括中间结点）到最后一个链表结点为后半部分。
 > 3. 由2中的前半部分链表递归地生成根节点的左子树，由2中的后半部分链表递归地生成根节点的右子树。
 
 ## 2. 解题算法与伪代码实现
 假设原始输入链表为head。
 > 0. 预先处理特殊情况，包含链表为空或者链表的结点数为1（这也是递归终止条件，或者称为递归奠基）。
 
     if not head:
            return None
        elif head and not head.next:
            root=TreeNode(head.val)
            return root
 
 > 1. 使用快慢双指针法查找输入链表的中间结点，并将中间结点作为该树的根结点。
 
     fast=head      # 快指针
     slow=head      # 慢指针
     lastslow=None  # 慢指针的前驱结点
     
     while fast and fast.next:
         lastslow=slow
         
         fast=fast.next.next
         slow=slow.next
        
     root=ListNode(slow.val)   # 由输入链表的中间结点生成树的根结点
     
 > 2. 将输入链表从中间结点分为两部分，从第一个结点到中间结点（但不包括中间结点）为前半部分，从中间结点（但不包括中间结点）到最后一个链表结点为后半部分。
     lastslow.next=None        # 为链表的前半部分封口，生成链表的前半部分
     
 > 3. 由2中的前半部分链表递归地生成根节点的左子树，由2中的后半部分链表递归地生成根节点的右子树。
     root.left=sortedListToBST(head)         # 使用链表的前半部分生成根节点的左子树
     root.right=sortedListToBST(slow.next)   # 使用链表的后半部分生成根节点的右子树
     
     return root

 ## 3. 代码实现
 C++版本的实现代码请参见109. Convert Sorted List to Binary Search Tree.cpp，python版本的代码请参见109. Convert Sorted List to Binary Search Tree.py。
 
 ## 4. 可能存在的边缘易错情况
 本题中主要存在以下两种容易出现错误的边缘情况。
 > 1. 原始链表为空链表，这时直接返回None或者NULL即可。
 > 2. 原始链表为只含有一个结点的链表，这时链表的前半段为空，在上述算法描述的步骤2中lastslow.next=None语句处会出现错误，解决方案是直接使用特判，当原始链表只有一个结点时，直接创建并返回包含该值的根节点。
 
 ## 5. 复杂度分析
 因为创建树的过程中，链表的每一个结点都访问仅一次，因此时间复杂度为O(n)。
     
     
     
 
