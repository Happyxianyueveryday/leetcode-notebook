
// 本题是栈专题下非常经典的一道习题，不论在考研试卷还是在面试笔试中都非常常见

// 本题中所使用的算法步骤可以简述为: 
// 1. 初始化游标下标now1=0, now2=0
// 2. 循环进行下列步骤直到now2>=popped.size()时停止: 判断当前栈顶元素是否与popped[now2]相等，若相等，则直接将当前栈顶元素出栈，并开始处理出栈序列的下一个元素，即将now2增加1；若不相等，则依次将入栈序列中的元素依次入栈，并同时增加now1，直到栈顶元素等于popped[now2]为止，若入栈序列中已经没有可用的元素，则说明序列不匹配，直接返回false
// 3. 若上述循环执行完毕，则说明入栈序列和出栈序列完全匹配，返回true

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sta;   // 临时栈
        int pos=0;        // 入栈序列的游标指针

        for(int i=0;i<popped.size();i++)   // 依次目标输出每个出栈序列中的元素
        {
            while(!(sta.size()&&sta.top()==popped[i]))   // 依次将入栈序列的元素入栈，直到栈中存在元素且栈顶元素和当前要输出的出栈序列元素为止
            {
                if(pos==pushed.size())   // 若入栈序列中已经没有元素可用，则直接返回false，匹配失败
                    return false;
                else
                {
                    sta.push(pushed[pos]);
                    pos+=1;
                }
            }
            sta.pop();       // 从栈顶输出目标输出的元素，并转向处理下一个元素
        }

        return true;
    }
};