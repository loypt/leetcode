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
    bool isPalindrome(ListNode* head) {
        vector<int> list_array;
        while(head){
            list_array.emplace_back(head->val);
            head = head->next;
        }
        for (int lpos = 0, rpos = list_array.size()-1; lpos < rpos; ++lpos, --rpos) {
            if (list_array[lpos] != list_array[rpos]){
                return false;
            }
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    ListNode *head, *p;
    vector<int> nums = {1,2,2,1};
    for (int num:nums) {
        if(!p){
            p = head = new ListNode(num);
        }else{
            head->next = new ListNode(num);
            head=  head->next;
        }
    }
    Solution solution;
    cout << solution.isPalindrome(p);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

