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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        ListNode *odd = head;
        ListNode *evenHead = head->next;
        ListNode *even = evenHead;
        while (even != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head, *p;
    p = head = nullptr;
    vector<int> nums = {2,1,3,5,6,4,7};
    for (int num:nums) {
        if(!p){
            p = head = new ListNode(num);
        }else{
            head->next = new ListNode(num);
            head=  head->next;
        }
    }
    Solution solution;
    ListNode *res_node = solution.oddEvenList(p);
    while (res_node){
        cout << res_node->val << " ";
        res_node = res_node->next;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

