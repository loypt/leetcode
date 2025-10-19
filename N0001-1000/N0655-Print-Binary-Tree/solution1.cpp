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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = get_height(root), w = get_width(root);
        vector<vector<string>> ans(h, vector<string>(w, ""));
        helper(ans, root, 0, 0, w-1);
        return ans;
    }
private:
    int get_height(TreeNode* p) {
        if (!p) return 0;
        int left = get_height(p->left), right = get_height(p->right);
        return max(left, right)+1;
    }
    int get_width(TreeNode* p) {
        if (!p) return 0;
        int left = get_width(p->left), right = get_width(p->right);
        return max(left, right)*2+1;
    }
    void helper(vector<vector<string>>& ans, TreeNode* p, int level, int l, int r) {
        if (!p) return;
        int mid = l+(r-l)/2;
        ans[level][mid] = to_string(p->val);
        helper(ans, p->left, level+1, l, mid-1);
        helper(ans, p->right, level+1, mid+1, r);
    }
};