class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        sta=[]    # 程序所使用的临时栈
        
        for i in range(len(s)):
            if s[i]=='(' or s[i]=='[' or s[i]=='{':
                sta.append(s[i])
            else:
                if sta:
                    if (sta[-1]=='{' and s[i]=='}') or (sta[-1]=='(' and s[i]==')') or (sta[-1]=='[' and s[i]==']'):
                        sta.pop()
                    else:
                        return False
                else:
                    return False
            
        if sta:
            return False
        else:
            return True