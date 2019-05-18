
// 本题是栈专题下非常经典的一道习题，不论在考研试卷还是在面试笔试中都非常常见

// 本题中所使用的算法步骤可以简述为: 
// 1. 初始化游标下标now1=0, now2=0
// 2. 循环进行下列步骤直到now2>=popped.size()时停止: 判断当前栈顶元素是否与popped[now2]相等，若相等，则直接将当前栈顶元素出栈，并开始处理出栈序列的下一个元素，即将now2增加1；若不相等，则依次将入栈序列中的元素依次入栈，并同时增加now1，直到栈顶元素等于popped[now2]为止，若入栈序列中已经没有可用的元素，则说明序列不匹配，直接返回false
// 3. 若上述循环执行完毕，则说明入栈序列和出栈序列完全匹配，返回true

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int now1=0, now2=0;

        stack<int> sta;

        while(now2<popped.size())  
        {
            // 1. 若栈顶元素和出栈序列中的当前元素不相等，或者栈为空，则依次将入栈序列中的元素入栈
            while((!sta.size()||sta.top()!=popped[now2])&&now1<pushed.size())
            {
                sta.push(pushed[now1]);
                now1+=1;
            }

            // 2. 上述步骤结束后，判断上述循环的退出原因

            // 2.1. 若因为栈顶元素是否和目标元素相等退出循环，则说明正确，先出栈栈顶元素，然后将now2+=1转向处理下一个出栈元素
            if(sta.top()==popped[now2])
            {
                sta.pop();
                now2+=1;       // 转向处理出栈序列中的下一个元素
            }

            // 2.2. 若因为入栈序列中已经没有更多的元素而退出循环，则说明不匹配，直接返回false
            else
            return false;
        }

        return true;      
    }
};