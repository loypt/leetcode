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
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution{
public:
    ListNode* sortList(ListNode* head){
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail){
        // Recursive termination condition
        if (head == nullptr){
            return head;
        }
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }

        ListNode *slow_pos = head, *fast_pos = head;
        while (fast_pos != tail){
            slow_pos = slow_pos->next;
            fast_pos = fast_pos->next;
            if (fast_pos!= tail){
                fast_pos = fast_pos->next;
            }
        }
        ListNode* mid = slow_pos;
        return mergeTwoLists(sortList(head, mid), sortList(mid, tail));
    }

    // ordered linked list merge
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If null then retuan another list
        if (!list1) {
            return list2;
        } else if(!list2) {
            return list1;
        } else if(list1->val < list2->val) { // Recursion Condition
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head, *p;
    vector<int> nums = {4,2,1,3};
    head = p = nullptr;
    for (int num: nums) {
        if(!p){
            p = head = new ListNode(num);
        }else{
            head->next = new ListNode(num);
            head = head->next;
        }
    }
    string n = "10";
    Solution solution;
    ListNode *pres = solution.sortList(p);
    while (pres){
        cout << pres->val << endl;
        pres = pres->next;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

