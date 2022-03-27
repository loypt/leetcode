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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while(!que.empty()){
            int qsize = que.size();
            while(qsize>0){
                TreeNode* node = que.front();
                que.pop();
                qsize -= 1;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ans+=1;
        }
        return ans;
    }
};
