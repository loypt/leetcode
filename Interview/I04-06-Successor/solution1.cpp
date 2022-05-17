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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr, *curr = root;
        while(!stk.empty() || curr != nullptr){
            while(curr != nullptr){
                stk.emplace(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if(prev == p){
                return curr;
            }
            prev = curr;
            curr = curr->right;
        }
        return nullptr;
    }
};
