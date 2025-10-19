//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace std::chrono;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    struct Node_status {
        int val;
        ListNode *ptr;
        bool operator < (const Node_status &rhs) const {
            return val > rhs.val;
        }
    };
    priority_queue<Node_status> que;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if(node) que.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!que.empty()){
            auto f = que.top();
            que.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next){
                que.push({f.ptr->next->val, f.ptr->next});
            }
        }
        return head.next;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> lists_num = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    ListNode *p, *res;
    vector<ListNode*> lists(lists_num.size());
    for (int i = 0; i < lists_num.size(); ++i) {
        p = nullptr;
        for (int j = 0; j < lists_num[i].size(); ++j) {
            if(!p){
                lists[i] = p = new ListNode(lists_num[i][j]);
            }else{
                p->next = new ListNode(lists_num[i][j]);
                p = p->next;
            }
        }
    }
    Solution solution;
    res = solution.mergeKLists(lists);
    while(res){
        cout << res->val << endl;
        res = res->next;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

