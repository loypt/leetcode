//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/11/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0 ){
            return head;
        }
        int n = 1;
        ListNode* iter = head;
        while(iter->next != nullptr){
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n){
            return head;
        }
        iter->next = head;
        while(add--){
            iter = iter->next;
        }
        ListNode* resHead = iter->next;
        iter->next = nullptr;
        return resHead;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head, *p;
    head = p = nullptr;
    for (const auto& num: nums) {
        if(!p){
            p = head = new ListNode(num);
        }else{
            p->next = new ListNode(num);
            p = p->next;
        }
    }
    int k = 2;
    Solution solution;
    ListNode* resNode = solution.rotateRight(head, k);
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


