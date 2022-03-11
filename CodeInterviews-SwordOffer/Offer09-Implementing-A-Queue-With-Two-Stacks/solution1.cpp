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

class CQueue {
    stack<int> stack1, stack2;
public:
    CQueue() {
        while (!stack1.empty()){
            stack1.pop();
        }
        while(!stack2.empty()){
            stack2.pop();
        }
    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()){
            return -1;
        }else{
            int deletedItem = stack2.top();
            stack2.pop();
            return deletedItem;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    CQueue obj;
    obj.appendTail(10);
    obj.appendTail(12);
    obj.appendTail(11);
    obj.appendTail(15);
    cout << obj.deleteHead() << endl;
    cout << obj.deleteHead() << endl;
    cout << obj.deleteHead() << endl;
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


