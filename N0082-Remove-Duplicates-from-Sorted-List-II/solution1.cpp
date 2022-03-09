//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/9/22.
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

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if (!head){
            return head;
        }
        ListNode* dummy = new ListNode(0, head);

        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val){
                int x  = cur->next->val;
                while (cur->next && cur->next->val == x){
                    cur->next = cur->next->next;
                }
            }
            else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head, *p;
    vector<int> nums = {1, 2, 3, 3, 4, 4, 5};
    p = head = nullptr;
    for (int num:nums) {
        if (!p){
            p = head  = new ListNode(num);
        }else{
            head->next = new ListNode(num);
            head = head->next;
        }
    }
    Solution solution;
    ListNode* resNode = solution.deleteDuplicates(p);
    while(resNode){
        cout << resNode->val << " ";
        resNode = resNode->next;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


