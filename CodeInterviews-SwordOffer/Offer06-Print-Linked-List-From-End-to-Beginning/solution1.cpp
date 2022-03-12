//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/11/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <stack>

using namespace std;
using namespace std::chrono;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*> mystack;
        ListNode* temp = head;
        while (temp){
            mystack.push(temp);
            temp = temp->next;
        }
        int size = mystack.size();
        vector<int> print(size);
        for (int i = 0; i < size; ++i) {
            print[i] = mystack.top()->val;
            mystack.pop();
        }
        return print;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head, *p;
    head = p = new ListNode(1);
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(2);
    Solution solution;
    vector<int> res =  solution.reversePrint(p);
    for (const auto& num:res) {
        cout<< num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


