
// 括号匹配是最简单和最基本的栈的应用
// 基本算法思路：依次遍历每一个元素，若当前元素是左括号则将其入栈，若为右括号，若栈为空，或者栈顶元素和当前右括号不匹配，则直接返回false，若栈顶元素和右括号匹配，则从栈顶出栈一个元素，然后继续遍历剩下的括号部分，循环结束后若栈为空，则返回true，否则返回false

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;   // 用于处理的栈
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='['||s[i]=='{'||s[i]=='(')
            sta.push(s[i]);
            else
            {
                if(sta.size()&&(sta.top()=='['&&s[i]==']'||sta.top()=='('&&s[i]==')'||sta.top()=='{'&&s[i]=='}'))
                sta.pop();
                else
                return false;
            }
        }

        if(sta.size())
        return false;
        else
        return true;
    }
};