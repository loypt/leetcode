//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <stack>

using namespace std;
using namespace std::chrono;

// Use second stack
class MinStack {
    stack<int> main_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX); // Init
    }

    void push(int val) {
        main_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }

    void pop() {
        main_stack.pop();
        min_stack.pop();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "minStack.getMin() : " << minStack.getMin() << endl;
    minStack.pop();
    cout << "minStack.top() : " << minStack.top() << endl;
    cout << "minStack.getMin() : " << minStack.getMin() << endl;
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

