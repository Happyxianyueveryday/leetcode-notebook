# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 本题将插入排序结合链表的基本操作进行考察：只需要熟练掌握插入排序算法以及链表插入以及删除的操作即可完成
# 插入排序算法：对于第i个元素，在此之前我们已经将前i-1个元素排序好，因此只需从头开始进行搜索，当搜索到合适的位置时，将第i个元素从原位置删除，并插入到该位置即可
# 链表的插入和删除算法：不论是链表的插入还是删除，均只需要重点关注和查找插入点或者删除点的前驱结点，即可完成快速插入和删除操作

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 0. 处理特殊情况，若给定的链表为空，或者链表的长度为1，则无需排序，直接返回即可
        if not head or not head.next:
            return head
        
        # 1. 为原始链表增加一个头部哑结点，简化插入排序代码
        newhead=ListNode(0)
        newhead.next=head
        head=newhead

        # 2. 从第二个结点开始插入排序过程，将第i个结点，插入到前i-1个元素组成的有序链表中
        pos=head.next.next    # 当前处理和进行插入的结点，从第二个结点开始
        posback=head.next     # 游标指针pos的前驱指针，用于从原位置删除当前结点

        while pos:
            now=head.next         # 遍历前i-1个结点的游标指针
            nowback=head          # 游标指针now的前驱指针，用于在适当位置插入当前结点

            # 2.1. 在前i-1个结点组成的有序链表中，查找第一个大于当前结点的值的结点位置now，然后使用now的前驱结点nowback，插入当前结点
            while now!=pos:          # now==pos时，表明当前结点大于有序部分的所有结点
                if now.val>pos.val:  # 适当的插入点
                    break
                else:
                    nowback=now
                    now=now.next
            
            # 现在now指向插入点之后的结点，nowback指向插入点位置的前驱结点
            # 2.2 若now==pos，即当前元素大于前面所有的i-1个已经排序的元素，这时保持不动，直接更新游标指针pos即可
            if now==pos:
                posback=pos
                pos=pos.next
            # 2.3 否则，需要将pos从原位置删除，并插入到新的位置上
            else:
                # 2.3.1 从原位置删除结点pos
                posback.next=pos.next

                # 2.3.2 将pos插入到nowback之后，now之前
                pos.next=nowback.next
                nowback.next=pos

                # 2.3.3 更新指针pos和backpos
                # backpos不变，因为移动了pos结点
                pos=posback.next
        
        return head.next
            

        



        