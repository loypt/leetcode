class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (poppedPos.empty()) {
            int pos = stk.size();
            stk.emplace_back(val);
            if (pos % capacity == 0) {
                top.emplace_back(0);
            } else {
                top.back()++;
            }
        } else {
            int pos = *poppedPos.begin();
            poppedPos.erase(pos);
            stk[pos] = val;
            int index = pos / capacity;
            top[index]++;
        }
    }
    
    int pop() {
        while (!stk.empty() && poppedPos.count(stk.size() - 1)) {
            stk.pop_back();
            int pos = *poppedPos.rbegin();
            poppedPos.erase(pos);
            if (pos % capacity == 0) {
                top.pop_back();
            }
        }
        if (stk.empty()) {
            return -1;
        } else {
            int pos = stk.size() - 1;
            int val = stk.back();
            stk.pop_back();
            if (pos % capacity == 0) {
                top.pop_back();
            } else {
                top.back() = top.size() - 2;
            }
            return val;
        }
    }
    
    int popAtStack(int index) {
        if (index >= top.size()) {
            return -1;
        }
        int stackTop = top[index];
        if (stackTop < 0) {
            return -1;
        }
        top[index]--;
        int pos = index * capacity + stackTop;
        poppedPos.emplace(pos);
        return stk[pos];
    }
private:
    int capacity;
    vector<int> stk;
    vector<int> top;
    set<int> poppedPos;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
