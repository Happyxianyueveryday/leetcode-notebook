
# 较为典型的习题，考察栈的使用

# 算法基本思路：首先利用斜杠'/'将路径的各个名称片段分开，然后使用一个栈依次遍历得到的这些名称片段，若遇到普通路径，则将其放入栈，若遇到'..'，则从栈顶出栈一个元素，若遇到'.'或者''则直接跳过不处理，最后将栈中剩下的元素依次出栈，头部加上一个斜杠/然后反向连接即可

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        res=''

        sta=[]

        path=path.split('/')

        for i in range(len(path)):
            if path[i]=='..':
                if sta:
                    sta.pop()
            elif path[i]=='.' or path[i]=='':
                pass
            else:
                sta.append(path[i])
        
        if sta:
            while sta:
                res='/'+sta[-1]+res
                sta.pop()
        else:
            res='/'
        
        return res
            

        