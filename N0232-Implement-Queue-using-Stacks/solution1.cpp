class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int front;
public:
    MyQueue() {
        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
    }
    
    void push(int x) {
        if(s1.empty()){
            front = x;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int popped = s1.top();
        s1.pop();
        if(!s1.empty()){
            front = s1.top();
        }
        return popped;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
