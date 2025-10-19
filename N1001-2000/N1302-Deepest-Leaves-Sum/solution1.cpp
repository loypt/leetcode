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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, i;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            for(i = que.size()-1, res = 0; i >= 0; --i){
                TreeNode* node = que.front();
                que.pop();
                res += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return res;
    }
};
