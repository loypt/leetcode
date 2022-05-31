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
    int dfs(TreeNode *root, int val) {
        if (root == nullptr) {
            return 0;
        }
        val = (val << 1) | root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return val;
        }
        return dfs(root->left, val) + dfs(root->right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
