//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/26/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr){
            ListNode* node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        return prev;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head, *p;
    vector<int> nums = {1, 2, 3, 4, 5};
    for(const auto& num: nums){
        if (!p){
            p  = head = new ListNode(num);
        }else{
            p->next = new ListNode(num);
            p = p->next;
        }
    }
    Solution solution;
    ListNode* resNode = solution.reverseList(head);
    while (resNode){
        cout << resNode->val << endl;
        resNode = resNode->next;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


