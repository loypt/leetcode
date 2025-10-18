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
    unordered_map<int, int> count;
    int maxCount = 0;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for(auto &c : count){
            if(c.second == maxCount){
                res.push_back(c.first);
            }
        }
        return res;
    }
    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int s = node->val + dfs(node->left) + dfs(node->right);
        maxCount = max(maxCount, ++count[s]);
        return s;
    }
};
