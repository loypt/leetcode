class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        left.push_front(val);
        if (left.size() == right.size() + 2) {
            right.push_front(left.back());
            left.pop_back();
        }
    }

    void pushMiddle(int val) {
        if (left.size() == right.size() + 1) {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
    }

    void pushBack(int val) {
        right.push_back(val);
        if (left.size() + 1 == right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

    int popFront() {
        if (left.empty()) {
            return -1;
        }
        int val = left.front();
        left.pop_front();
        if (left.size() + 1 == right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
        return val;
    }

    int popMiddle() {
        if (left.empty()) {
            return -1;
        }
        int val = left.back();
        left.pop_back();
        if (left.size() + 1 == right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
        return val;
    }

    int popBack() {
        if (left.empty()) {
            return -1;
        }
        int val = 0;
        if (right.empty()) {
            val = left.back();
            left.pop_back();
        } else {
            val = right.back();
            right.pop_back();
            if (left.size() == right.size() + 2) {
                right.push_front(left.back());
                left.pop_back();
            }
        }
        return val;
    }
private:
    deque<int> left;
    deque<int> right;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
