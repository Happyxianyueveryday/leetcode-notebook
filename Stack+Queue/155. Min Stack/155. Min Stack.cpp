
// 相对较为简单的题目，主要的算法思想是: 使用两个栈，一个栈sta1用于像普通的栈一样存储数据，另外一个栈sta2用于存储当前栈sta1中的最小值:
// 1. 当要入栈时，先将当前元素入栈sta1，然后将当前元素的值和栈sta2的栈顶元素进行比较，若当前元素小于或者等于（注意等于也要入栈）sta2的栈顶元素，则将当前元素入栈sta2
// 2. 当要出栈时，先从sta1的栈顶出栈一个元素，若出栈的元素值等于栈sta2的栈顶元素，则将sta2的栈顶元素也进行出栈

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        sta1.push(x);

        if(!sta2.size()||x<=sta2.top())
        sta2.push(x);
    }
    
    void pop() {
        int tar=sta1.top();
        sta1.pop();

        if(sta2.size()&&sta2.top()==tar)
        sta2.pop();
    }
    
    int top() {
        return sta1.top();
    }
    
    int getMin() {
        return sta2.top();
    }

    private:
    stack<int> sta1;   // 普通栈
    stack<int> sta2;   // 记录栈中的最小值的栈
}; 

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */