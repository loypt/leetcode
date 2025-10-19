/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }

    bool isleafnode(TreeNode* node){
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node){
        int ans = 0;
        if(node->left){
            ans += isleafnode(node->left) ? node->left->val : dfs(node->left);
        }
        if(node->right){
            ans += dfs(node->right);
        }
        return ans;
    }
};
