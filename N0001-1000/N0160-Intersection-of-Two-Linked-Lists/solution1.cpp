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
#include <unordered_set>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        ListNode *temp = headA;
        while (temp != nullptr){
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr){
            if (visited.count(temp)){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head1, *p1, *head2, *p2, *ptemp;
    vector<int> nums1 = {4,1,8,4,5};
    vector<int> nums2 = {5,6,1};
    head1 = p1 = nullptr;
    for (int num: nums1) {
        if(!p1){
            p1 = head1 = new ListNode(num);
        }else{
            head1->next = new ListNode(num);
            head1 = head1->next;
        }
    }
    for (int num: nums2) {
        if(!p2){
            p2 = head2 = new ListNode(num);
        }else{
            head2->next = new ListNode(num);
            head2 = head2->next;
        }
    }
    head1 = p1;
    head1 = head1->next->next;
    head2->next = head1;
    Solution solution;
    ListNode *pres = solution.getIntersectionNode(p1, p2);
    cout << pres->val;
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

