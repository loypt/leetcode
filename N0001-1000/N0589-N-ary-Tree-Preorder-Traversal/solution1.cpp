//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/10/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        recursion(root ,res);
        return res;
    }

    void recursion(const Node* root, vector<int>& res){
        if (root == nullptr){
            return;
        }
        res.emplace_back(root->val);
        for (auto& ch: root->children) {
            recursion(ch, res);
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    Node *aNode = new Node(1);
    Node *bNode = new Node(3);
    Node *cNode = new Node(2);
    Node *dNode = new Node(4);
    Node *eNode = new Node(5);
    Node *fNode = new Node(6);
    aNode->children = {bNode, cNode, dNode};
    bNode->children = {eNode, fNode};
    Solution solution;
    vector<int> resArray = solution.preorder(aNode);
    for (const auto& num:resArray) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


