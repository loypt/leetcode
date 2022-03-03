//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/3/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head, *p;
    vector<int> nums = {4, 5, 1, 9};
    for (int num:nums) {
        if(!p){
            p = head = new ListNode(num);
        }else{
            head->next = new ListNode(num);
            head=  head->next;
        }
    }
    ListNode *nodein = p->next;
    Solution solution;
    solution.deleteNode(nodein);
    while (p){
        cout << p->val << " ";
        p = p->next;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

