/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res, k;
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        dfs(root->right);
        if(k == 0) return;
        if(--k == 0) res = root->val;
        dfs(root->left);
    }
};
