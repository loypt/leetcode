//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/4/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }

    bool dfs(TreeNode *root, TreeNode* p, TreeNode* q){
        if (root == nullptr){
            return false;
        }
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            res = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
};



int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nodeval = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* nodeA = new TreeNode(nodeval[0]);
    TreeNode* nodeB = new TreeNode(nodeval[1]);
    TreeNode* nodeC = new TreeNode(nodeval[2]);
    TreeNode* nodeD = new TreeNode(nodeval[3]);
    TreeNode* nodeE = new TreeNode(nodeval[4]);
    TreeNode* nodeF = new TreeNode(nodeval[5]);
    TreeNode* nodeG = new TreeNode(nodeval[6]);
    TreeNode* nodeH = new TreeNode(nodeval[9]);
    TreeNode* nodeI = new TreeNode(nodeval[10]);
    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->left = nodeF;
    nodeC->right = nodeG;
    nodeE->left = nodeH;
    nodeE->right = nodeI;
    TreeNode *head = nodeA;
    TreeNode *p = nodeB;
    TreeNode *q = nodeI;
    Solution solution;
    cout << solution.lowestCommonAncestor(head, p, q)->val;
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

