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

class Node{
public:
    int val;
    vector<Node*> children;

    Node() {};
    Node(int _val){
        val = _val;
    }

    Node(int _val, vector<Node*> _children){
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(Node* root, vector<int>& res){
        if (root == nullptr){
            return;
        }
        for (auto&  child:root->children) {
            helper(child, res);
        }
        res.emplace_back(root->val);
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    Node *nodeA = new Node(1);
    Node *nodeB = new Node(3);
    Node *nodeC = new Node(2);
    Node *nodeD = new Node(4);
    Node *nodeE = new Node(5);
    Node *nodeF = new Node(6);
    nodeA->children = {nodeB, nodeC, nodeD};
    nodeB->children = {nodeE, nodeF};
    Solution solution;
    vector<int> resArray = solution.postorder(nodeA);
    for(const auto& num: resArray){
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


