//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions){
        unordered_map<int ,TreeNode*> nodemap;
        unordered_set<int> nodeSet1, nodeSet2;
        for (const auto& d:descriptions) {
            int pv=d[0], sv=d[1], isLeft = d[2];
            nodeSet1.insert(pv); // Parent Node
            nodeSet2.insert(sv); // Son node
            TreeNode* child;
            if (!nodemap.count(sv)){
                child = new TreeNode(sv);
                nodemap[sv] = child;
            }else{
                child = nodemap[sv];
            }

            if (!nodemap.count(pv)){
                nodemap[pv] = new TreeNode(pv); // Parent TreeNode
            }
            if (isLeft){
                nodemap[pv]->left = child;
            }else{
                nodemap[pv]->right = child;
            }
        }
        int pnpos=0;
        for (const auto& x:nodeSet1) {
            if (nodeSet2.find(x) == nodeSet2.end()){
                pnpos = x;
                break;
            }
        }
        return nodemap[pnpos];
    }
};

int height(TreeNode* root){
    if (root == nullptr){
        return 0;
    }else{
        int l = height(root->left);
        int r = height(root->right);
        if (l>r)
            return (l+1);
        else
            return r+1;
    }
}

void currentlevel(TreeNode *root, int k){
    if (root == nullptr)
        return;
    if (k == 1)
        cout << root->val << " ";
    else if(k > 1){
        currentlevel(root->left, k-1);
        currentlevel(root->right, k-1);
    }
}

void bfs(TreeNode* root){
    for (int i = 1; i <= height(root); ++i) {
        currentlevel(root, i);
    }
}


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> descriptions = {{20,15,1}, {20,17,0}, {50,20,1}, {50,80,0}, {80,19,1}};
    Solution solution;
    TreeNode *resNode = solution.createBinaryTree(descriptions);
    bfs(resNode);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


