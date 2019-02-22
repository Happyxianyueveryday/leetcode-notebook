# 82. Remove Duplicates from Sorted List II

# 1. 基本算法思想
由于按照题目要求，需要删除掉所有出现重复的值的结点，因此可能需要删除头结点，我们需要使用哑结点作为头结点。具体算法步骤简述如下。

> 1. 向原始链表的头结点之前插入一个哑结点，记新的头结点为head。
> 2. 创建一个游标指针pos，初始化为head->next，该游标指针规定指向链表中第一个等于某个值的结点；创建另一个游标指针lastpos，初始化为head，规定该结点必须保持是pos的前驱结点。（为了删除重复值出现的片段，首先应当查找某个固定的重复值出现的第一个结点pos的前驱结点）
> 3. 若pos和pos.next均不为空结点，则循环执行下列步骤a到c（若pos.next为空，则不可能出现与pos相等的重复值结点，因此作为判断条件）：
>> a. pos和pos.next的值若不相等，则说明pos后面没有与pos相等的结点；这时更新游标指针：lastpos=pos, pos=pos.next。  
>> b. pos和pos.next的值若相等，则说明pos后存在与pos相等的重复结点；这时首先查找pos后第一个与pos不相等的结点now（也有可能该结点不存在，now=NULL)，然后连接lastpos和now，即lastpos.next=now，并删除中间的结点；最后更新指针：lastpos保持不变，pos=now。
> 4. 返回处理后的链表头结点head.next。

# 2. 伪代码实现


# 3. 代码实现
C++实现代码请参见82. Remove Duplicates from Sorted List II.cpp，python实现代码请参见82. Remove Duplicates from Sorted List II.py。


# 4. 易错的边缘情况


# 5. 算法复杂度分析


