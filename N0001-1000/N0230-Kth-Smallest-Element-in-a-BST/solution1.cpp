//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/26/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int count = 0;
    int ans = -1;
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
    void dfs(TreeNode* root, int k){
        if (root == NULL ||  ans!= -1){
            return;
        }
        dfs(root->left, k);
        ++count;
        if (count==k) ans=root->val;
        dfs(root->right, k);

    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nodeval = {5,3,6,2,4,-1,-1,1};
    TreeNode* nodeA = new TreeNode(nodeval[0]);
    TreeNode* nodeB = new TreeNode(nodeval[1]);
    TreeNode* nodeC = new TreeNode(nodeval[2]);
    TreeNode* nodeD = new TreeNode(nodeval[3]);
    TreeNode* nodeE = new TreeNode(nodeval[4]);
    TreeNode* nodeF = new TreeNode();
    TreeNode* nodeG = new TreeNode();
    TreeNode* nodeH = new TreeNode(nodeval[7]);
    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->left = nodeF;
    nodeC->right = nodeG;
    nodeD->left = nodeH;
    TreeNode* head = nodeA;
    int k = 3;
    Solution solution;
    cout << solution.kthSmallest(head, 3);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
