//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/12/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next){};
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr){
            ++n;
            cur = cur->next;
        }
        int k = 0;
        cur = head;
        while(k < n / 2){
            ++k;
            cur = cur->next;
        }
        return cur;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head, *p;
    for(const auto& num: nums){
        if (!p){
            p = head = new ListNode(num);
        }else{
            head->next = new ListNode(num);
            head = head->next;
        }
    }
    Solution solution;
    ListNode* resNode = solution.middleNode(p);
    while(resNode){
        cout << resNode->val << endl;
        resNode = resNode->next;
    }

    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


