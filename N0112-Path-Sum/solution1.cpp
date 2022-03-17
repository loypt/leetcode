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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return root;
        }
        queue<TreeNode* > nodeque;
        queue<int> valque;
        nodeque.push(root);
        valque.push(root->val);
        while(!nodeque.empty()){
            TreeNode* node = nodeque.front();
            int temp = valque.front();
            nodeque.pop();
            valque.pop();
            if(node->left == nullptr && node->right == nullptr){
                if(temp == targetSum){
                    return true;
                }
                continue;
            }
            if(node->left){
                nodeque.push(node->left);
                valque.push(temp+node->left->val);
            }
            if(node->right){
                nodeque.push(node->right);
                valque.push(temp+node->right->val);
            }
        }
        return false;
    }
};
