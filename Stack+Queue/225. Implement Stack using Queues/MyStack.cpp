class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> que2;
	
	while(que1.size()>1)
	{
		que2.push(que1.front());
		que1.pop();
	}
	
	int res=que1.front();
	que1.pop();
	
	while(que2.size())
	{
		que1.push(que2.front());
		que2.pop();
	}
	
	return res;
    }
    
    /** Get the top element. */
    int top() {
        queue<int> que2;
	int res;
	
	while(que1.size())
	{
		res=que1.front();
		que2.push(res);
		que1.pop();
	}
	
	while(que2.size())
	{
		que1.push(que2.front());
		que2.pop();
	}
	
	return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        queue<int> que2;
	int count=0;
	
	while(que1.size())
	{
		que2.push(que1.front());
		que1.pop();
		count+=1;
	}
	
	while(que2.size())
	{
		que1.push(que2.front());
		que2.pop();
	}
	
	if(!count)
        return true;
    else
        return false;
    }
    
    private:
    queue<int> que1;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
