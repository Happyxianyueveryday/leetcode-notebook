class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sta1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> sta2;
	
	while(sta1.size())
	{
		sta2.push(sta1.top());
		sta1.pop();
	}
	
	int res=sta2.top();
	sta2.pop();
	
	while(sta2.size())
	{
		sta1.push(sta2.top());
		sta2.pop();
	}
	
	return res;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> sta2;
	
	while(sta1.size())
	{
		sta2.push(sta1.top());
		sta1.pop();
	}
	
	int res=sta2.top();
	
	while(sta2.size())
	{
		sta1.push(sta2.top());
		sta2.pop();
	}
	
	return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        int count=0;
	stack<int> sta2;
	
	while(sta1.size())
	{
		sta2.push(sta1.top());
		sta1.pop();
		count+=1;
	}
	
	while(sta2.size())
	{
		sta1.push(sta2.top());
		sta2.pop();
	}
	
	if(!count)
        return true;
        else
            return false;
    }
    
private:
    stack<int> sta1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
