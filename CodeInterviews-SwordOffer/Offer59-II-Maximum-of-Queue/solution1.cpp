class MaxQueue {
    int q[20000];
    int begin=0, end=0;
public:
    MaxQueue() {
    }
    
    int max_value() {
        int ans = -1;
        for(int i = begin; i != end; i++){
            ans = max(ans, q[i]);
        }
        return ans;
    }
    
    void push_back(int value) {
        q[end++] = value;
    }
    
    int pop_front() {
        if(begin == end){
            return -1;
        }
        return q[begin++];
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
