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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> arr;
        function<void(TreeNode*)> dfs = [&](TreeNode *root) {
            if (!root) {
                return;
            }    
            dfs(root->left);
            arr.emplace_back(root->val);
            dfs(root->right);
        };
        dfs(root);

        vector<vector<int>> res;
        for (int val : queries) {
            int maxVal = -1, minVal = -1;
            auto it = lower_bound(arr.begin(), arr.end(), val);
            if (it != arr.end()) {
                maxVal = *it;
                if (*it == val) {
                    minVal = *it;
                    res.push_back({minVal, maxVal});
                    continue;
                }
            }
            if (it != arr.begin()) {
                minVal = *(--it);
            }
            res.push_back({minVal, maxVal});
        }
        return res;
    }
};
