//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

using namespace std;
using namespace std::chrono;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    bool hasCycle(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode *slow_pos = head;
        ListNode *fast_pos = head->next;
        while (slow_pos != fast_pos){
            if (fast_pos == nullptr || fast_pos->next == nullptr){
                return false;
            }
            slow_pos = slow_pos->next;
            fast_pos = fast_pos->next->next;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {3,2,0,-4};
    ListNode *head, *p, *q;
    p = head = nullptr;
    for (int num:nums) {
        if (!p){
            p = head = new ListNode(num);
        }else{
            head->next = new ListNode(num);
            head = head->next;
        }
    }
    q = p;
    int n = 1;
    while (n--&&q){
        q = q->next;
    }
    head->next = q;
    Solution solution;
    cout << solution.hasCycle(p);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

