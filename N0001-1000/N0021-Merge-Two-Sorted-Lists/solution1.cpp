//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2, int depth) {
        // If null then retuan another list
        string s(depth, ' ');
        cout << s;
        printList(list1, list2);
        cout << endl;
        if (!list1) {
            return list2;
        } else if(!list2) {
            return list1;
        } else if(list1->val < list2->val) { // Recursion Condition
            list1->next = mergeTwoLists(list1->next, list2, depth+1);
            string s(depth, ' ');
            cout << s;
            printList(list1, list2);
            cout << endl;
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next, depth+1);
            string s(depth, ' ');
            cout << s;
            printList(list1, list2);
            cout << endl;
            return list2;
        }
    }
    
    void printList(ListNode* list1, ListNode* list2) {
        cout << "[";
        while (list1) {
            cout << list1->val << " ";
            list1 = list1->next;
        }
        cout << "] [";
        while (list2) {
            cout << list2->val << " ";
            list2 = list2->next;
        }
        cout << "]";
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    ListNode *p1, *p2, *phead1, *phead2;
    vector<int> num1 = {1,2,4};
    vector<int> num2 = {1,3,4};
    
    p1 = p2 = phead1 = phead2 = nullptr;
    
    for (int num:num1) {
        if (!p1) {
            p1 = phead1 = new ListNode(num);
        }else{
            phead1->next = new ListNode(num);
            phead1 = phead1->next;
        }
    }
    
    for (int num:num2) {
        if (!p2) {
            p2 = phead2 = new ListNode(num);
        }else{
            phead2->next = new ListNode(num);
            phead2 = phead2->next;
        }
    }

    Solution solution;
    ListNode *p3 = solution.mergeTwoLists(p1, p2, 1);
    
    while (p3) {
        cout << p3->val << ", ";
        p3 = p3->next;
    }
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

