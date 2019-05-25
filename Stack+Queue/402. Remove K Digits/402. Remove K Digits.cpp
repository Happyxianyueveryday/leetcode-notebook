
// 使用栈的算法题，一般最常见的就是使用栈来维护一个递增/递减序列，以递增序列为例，当当前元素需要入栈时，首先将大于当前元素的元素依次出栈，再将当前元素入栈，便可以维护一个递增序列，从这个角度出发思考，本题就非常容易解答
// 本题的算法是较为朴素的: 要从原始n位整数中移出k位，则一定剩下(n-k)位；要保证剩下的(n-k)位数字最小，只要保证这(n-k)位中高位数字尽量的小，低位数字尽量的大；换句话说，就是要尽量地移除远数字中高位的较大值
// 综上所述，本题的算法简述为:
// (1) 创建一个临时栈，并使用一个临时变量count记录已经删除的位
// (2) 依次将数字的每一位（从高位到低位方向）入栈: 
//     (a) 若count<k，则先判断当前元素是否小于栈顶元素，若小于（这时说明栈顶元素在当前元素的左侧，即高位，根据上面的分析，应该尽量删除高位的较大值），则一直出栈直到当前元素大于栈顶元素或者count==k为止，每出栈一个元素将count加1，然后再将当前元素入栈
//     (b) 若count==k，则直接将当前元素入栈
// (3) 循环进行步骤(2)直到遍历完成时停止
// (4) 若遍历完成后count==k，则将栈中剩下的元素依次出栈作为结果输出即可
// (5) 若遍历完成后count<k，这时从栈顶到栈底必然为递增序列，则应该删除最大的(count-k)个元素，因此从栈顶出栈(count-k)个元素后，再将栈中剩下的元素作为结果输出

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> sta;
        string res;
        int count=0;

        for(int i=0;i<num.size();i++)
        {
            while(count<k&&sta.size()&&sta.top()>num[i])
            {
                count+=1;
                sta.pop();
            }
            sta.push(num[i]);
        }

        while(count<k)
        {
            sta.pop();
            count+=1;
        }

        string temp;
        while(sta.size())    // 这里使用了一个排除前导0的小技巧，遇到0就先放在temp里；遇到非0，先将temp和结果相连接，再将该非0值加入到结果中
        {
            char val=sta.top();
            sta.pop();

            if(val=='0')
            temp.push_back(val);
            else
            {
                res+=temp;
                res.push_back(val);
                temp="";
            }
        }
        
        reverse(res.begin(), res.end());

        if(res=="")
        return "0";
        else
        return res;
    }
};