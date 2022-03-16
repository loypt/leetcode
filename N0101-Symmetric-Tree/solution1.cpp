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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr ? true : dfs(root->left, root->right);
    }
    bool dfs(TreeNode* L, TreeNode* R){
        if(L == nullptr && R == nullptr) return true;
        if(L == nullptr || R == nullptr || L->val != R->val) return false;
        return dfs(L->left, R->right) && dfs(L->right, R->left);
    }
};
