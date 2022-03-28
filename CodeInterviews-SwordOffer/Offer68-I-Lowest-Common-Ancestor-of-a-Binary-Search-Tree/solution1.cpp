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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while(true){
            if(p->val < ancestor->val && q->val < ancestor->val){
                ancestor = ancestor->left;
            }else if(p->val > ancestor->val && q->val > ancestor->val){
                ancestor = ancestor->right;
            }else{
                break;
            }
        }
        return ancestor;
    }
};
