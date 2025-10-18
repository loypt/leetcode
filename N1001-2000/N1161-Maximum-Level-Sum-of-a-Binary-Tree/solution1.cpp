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
    int maxLevelSum(TreeNode *root) {
        int ans = 1, maxSum = root->val;
        vector<TreeNode*> q = {root};
        for (int level = 1; !q.empty(); ++level) {
            vector<TreeNode*> nq;
            int sum = 0;
            for (auto node : q) {
                sum += node->val;
                if (node->left) {
                    nq.emplace_back(node->left);
                }
                if (node->right) {
                    nq.emplace_back(node->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                ans = level;
            }
            q = move(nq);
        }
        return ans;
    }
};
