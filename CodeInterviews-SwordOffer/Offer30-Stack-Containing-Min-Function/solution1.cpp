//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/10/22.
//

#include <iostream>
#include <chrono>
#include <stack>

using namespace std;
using namespace std::chrono;

class MinStack {
    stack<int> s1;
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStack() {
        s2.push(INT_MAX);
    }

    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()){
            s2.push(x);
        }else{
            s2.push(s2.top());
        }
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    MinStack obj;
    obj.push(10);
    obj.push(12);
    obj.push(5);
    obj.push(4);
    obj.push(16);
    cout << obj.min() << endl;
    obj.pop();
    cout << obj.min() << endl;
    obj.pop();
    cout << obj.min() << endl;
    obj.pop();
    cout << obj.min() << endl;
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


