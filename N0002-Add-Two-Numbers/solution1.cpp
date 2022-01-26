//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1, *p2;
        int n1, n2, carry_num = 0;
        p1 = p2 = nullptr;
        while (l1 || l2) {
            if(l1){
                n1 = l1->val;
                l1 = l1->next;
            }else{
                n1 = 0;
            }
            if(l2){
                n2 = l2->val;
                l2 = l2->next;
            }else{
                n2 = 0;
            }
            int sum = n1 + n2 + carry_num;
            // if p1 is null
            if(!p1){
                p1 = p2 = new ListNode(sum%10);
            }else{
                p2->next = new ListNode(sum%10);
                p2 = p2->next;
            }
            carry_num = sum/10;
        }
        if (carry_num > 0) {
            p2->next = new ListNode(1);
        }
        
        return p1;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *p1,*p2,*phead1, *phead2;
    vector<int> nums1 = {2, 4, 3};
    vector<int> nums2 = {5, 6, 4};
    
    p1 = p2 = phead1 = phead2 = nullptr;
    
    for (int num:nums1) {
        if(!p1){
            p1 = phead1 = new ListNode(num);
        }else{
            phead1->next = new ListNode(num);
            phead1 = phead1->next;
        }
    }
    
    for (int num:nums2) {
        if(!p2){
            p2 = phead2 = new ListNode(num);
        }else{
            phead2->next = new ListNode(num);
            phead2 = phead2->next;
        }
    }
    
    phead1 = p1;
    cout << "Test p1 Link List" << endl;
    while (phead1) {
        cout << phead1->val << endl;
        phead1 = phead1->next;
    }
    
    phead2 = p2;
    cout << "Test p2 Link List" << endl;
    while (phead2) {
        cout << phead2->val << endl;
        phead2 = phead2->next;
    }
    
    cout << "Solution Print" << endl;
    Solution solution;
    ListNode *p3 = solution.addTwoNumbers(p1, p2);
    while (p3) {
        cout << p3->val << endl;
        p3 = p3->next;
    }
    return 0;
}

