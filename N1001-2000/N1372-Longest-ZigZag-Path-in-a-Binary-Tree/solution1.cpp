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
    unordered_map <TreeNode*, int> f, g;
    
    queue <pair <TreeNode *, TreeNode *>> q;
    
    void dp(TreeNode *o) {
        f[o] = g[o] = 0;
        q.push({o, nullptr});
        while (!q.empty()) {
            auto y = q.front(); q.pop();
            auto x = y.second, u = y.first;
            f[u] = g[u] = 0;
            if (x) {
                if (x->left == u) f[u] = g[x] + 1;
                if (x->right == u) g[u] = f[x] + 1;
            }
            if (u->left) q.push({u->left, u});
            if (u->right) q.push({u->right, u});
        }
    }
    
    int longestZigZag(TreeNode* root) {
        dp(root);
        int maxAns = 0;
        for (const auto &u: f) maxAns = max(maxAns, max(u.second, g[u.first]));
        return maxAns;
    }
};
