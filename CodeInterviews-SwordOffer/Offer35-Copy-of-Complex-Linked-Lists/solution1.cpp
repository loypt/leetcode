//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/26/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    /*
     * generate linklist with random
     */
    vector<int> nums = {7, 13, 11, 10, 1};
    vector<int> random_node = {-1, 0, 4, 2, 0};
    Node* head = new Node(nums[0]);
    Node* ptr = head;
    Node* new_ptr = head;
    for (int i = 1; i < nums.size(); i++) {
        Node* node = new Node(nums[i]);
        head->next = node;
        head = head->next;
    }
    for (int rn : random_node) {
        head = ptr;
        int new_rn = rn;
        while (rn > 0) {
            head = head->next;
            rn--;
        }
        if (new_rn >= 0) {
            new_ptr->random = head;
        }
        new_ptr = new_ptr->next;
    }
    new_ptr = ptr;
    while (new_ptr) {
        if (new_ptr->random){
            cout << "ptr->val: " << new_ptr->val << "  ptr->random->val: " << new_ptr->random->val << endl;
        }else {
            cout << "ptr->val: " << new_ptr->val << "  ptr->random->val: " <<  "null" << endl;
        }
        new_ptr = new_ptr->next;
    }
    head = ptr;
    Solution solution;
    Node* new_head = solution.copyRandomList(head);
    cout << "copyRandomList" << endl << endl;
    while (new_head) {
        if (new_head->random){
            cout << "ptr->val: " << new_head->val << "  ptr->random->val: " << new_head->random->val << endl;
        }else {
            cout << "ptr->val: " << new_head->val << "  ptr->random->val: " <<  "null" << endl;
        }
        new_head = new_head->next;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


