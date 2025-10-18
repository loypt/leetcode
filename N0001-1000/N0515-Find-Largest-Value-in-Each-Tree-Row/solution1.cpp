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
    vector<int> ans;
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr){
            return ans;
        }
        helper(root, 0);
        return ans;
    }

    void helper(TreeNode* node, int cl){
        if(node == nullptr){
            return;
        }
        if(ans.size() < cl + 1){
            ans.push_back(node->val);
        }else{
            if(ans[cl] < node->val){
                ans[cl] = node->val;
            }
        }
        helper(node->left, cl+1);
        helper(node->right, cl+1);
    }
};
