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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root){
        maxValue(root);
        return maxSum;
    }

    int maxValue(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        int leftValue = max(0, maxValue(node->left));
        int rightValue = max(0, maxValue(node->right));
        int pricePath = node->val + leftValue + rightValue;

        maxSum = max(maxSum, pricePath);

        return node->val + max(leftValue, rightValue);
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> root = {1,2,3};
    auto *nodeA = new TreeNode(root[0]);
    auto *nodeB = new TreeNode(root[1]);
    auto *nodeC = new TreeNode(root[2]);
    nodeA->left = nodeB;
    nodeA->right = nodeC;
    Solution solution;
    cout << solution.maxPathSum(nodeA);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

