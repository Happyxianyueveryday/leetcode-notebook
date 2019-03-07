# 计算逆波兰表达式是栈的重要应用之一，必须要熟练掌握，另外一个栈的相关应用是将普通表达式转化为逆波兰表达式
# 基本算法思想： 正向遍历输入的数组，若遇到数字，则将其直接入栈；若遇到符号，则从栈顶依次出栈两个元素进行相应的运算，再将结果入栈，最后栈中剩下的一个元素就是计算结果


class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        sta=[]

        for a in tokens:
            if a=="+":
                right=sta[-1]
                sta.pop()
                left=sta[-1]
                sta.pop()

                tempres=left+right
                sta.append(tempres)

            elif a=="-":
                right=sta[-1]
                sta.pop()
                left=sta[-1]
                sta.pop()

                tempres=left-right
                sta.append(tempres)

            elif a=="*":
                right=sta[-1]
                sta.pop()
                left=sta[-1]
                sta.pop()

                tempres=left*right
                sta.append(tempres)

            elif a=="/":
                right=sta[-1]
                sta.pop()
                left=sta[-1]
                sta.pop()

                if left*right<0 and left%right!=0:
                    sta.append(left/right+1)
                else:
                    sta.append(left/right)
            
            else:
                sta.append(int(a))
        
        return sta[-1]