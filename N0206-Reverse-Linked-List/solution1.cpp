//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/2/22.
//

#include <iostream>
#include <chrono>
#include <numeric>
#include <vector>

using namespace std;
using namespace std::chrono;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head, *p;
    p = head = nullptr;
    vector<int> nums = {1, 2, 3, 4, 5};
    for (int num : nums) {
        if (!p){
            p = head = new ListNode(num);
        }else {
            head->next = new ListNode(num);
            head = head->next;
        }
    }
    Solution solution;
    ListNode *pret = solution.reverseList(p);
    while(pret){
        cout << pret->val << " ";
        pret = pret->next;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

