# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

# 本题的算法和扁平化嵌套链表的题目类似
# 本题的基本算法步骤可以简述为: 首先将原始字符串分割为字符串数组，然后依次遍历字符串数组中的每一个元素:
#                             (1) 若当前元素是左括号或者嵌套列表，则直接入栈
#                             (2) 若当前元素是右括号，则不断将栈顶元素出栈并收集成为一个嵌套数组，直到栈顶元素为左括号为止，左括号出栈但是不输出到数组中，最后再将收集到的嵌套数组入栈
#                             遍历结束后，从栈中出栈剩下的一个元素，返回该元素作为最终结果

class Solution(object):
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        
        # 1. 遍历整个字符串，在左括号之后增加一个','，在右括号之前增加一个','
        tar=""
        for i in range(len(s)):
            if s[i]=='[':
                tar=tar+s[i]+','
            elif s[i]==']':
                tar=tar+','+s[i]
            else:
                tar+=s[i]
        
        # 2. 将原始字符串根据","分割为字符串数组
        lis=tar.split(',')
        print(lis)

        # 3. 使用一个栈，依次遍历整个字符串数组
        sta=[]

        for i in range(len(lis)):
            if lis[i]==']':
                templis=NestedInteger()
                gather=[]
                while sta[-1]!='[':
                    gather.append(sta[-1])
                    sta.pop()
                sta.pop()     # 出栈左括号但是不输出到数组中

                for i in range(len(gather)-1,-1,-1):
                    templis.add(gather[i])

                sta.append(templis)
            elif lis[i]=='[':
                sta.append(lis[i])
            else:
                sta.append(NestedInteger(lis[i]))

        return sta[-1]
                    