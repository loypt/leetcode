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
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    ListNode *p1, *phead;
    vector<int> nums = {1,2,3,4,5};
    
    for (int num: nums) {
        if (!p1) {
            p1 = phead = new ListNode(num);
        }else{
            phead->next = new ListNode(num);
            phead = phead->next;
        }
    }
    
    Solution solution;
    
    //Output normal constant
    /*
     cout << solution.letterCombinations(digits);
     */
    
    // Output Vectors
    ListNode* res = solution.removeNthFromEnd(p1, 2);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
