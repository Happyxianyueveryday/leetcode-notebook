
// 计算逆波兰表达式是栈的重要应用之一，必须要熟练掌握，另外一个栈的相关应用是将普通表达式转化为逆波兰表达式
// 基本算法思想： 正向遍历输入的数组，若遇到数字，则将其直接入栈；若遇到符号，则从栈顶依次出栈两个元素进行相应的运算，再将结果入栈，最后栈中剩下的一个元素就是计算结果

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;

        for(int i=0;i<tokens.size();i++)        
        {
            if(tokens[i]=="+")
            {
                int right=sta.top();
                sta.pop();
                int left=sta.top();
                sta.pop();

                int tempres=left+right;
                sta.push(tempres);
            }
            else if (tokens[i]=="-")
            {
                int right=sta.top();
                sta.pop();
                int left=sta.top();
                sta.pop();

                int tempres=left-right;
                sta.push(tempres);
            }
            else if(tokens[i]=="*")
            {
                int right=sta.top();
                sta.pop();
                int left=sta.top();
                sta.pop();

                int tempres=left*right;
                sta.push(tempres);
            }
            else if(tokens[i]=="/")
            {
                int right=sta.top();
                sta.pop();
                int left=sta.top();
                sta.pop();

                int tempres=left/right;
                sta.push(tempres);
            }
            else
            {
                sta.push(atoi(tokens[i].c_str()));
            }
        }

        return sta.top();
    }
};