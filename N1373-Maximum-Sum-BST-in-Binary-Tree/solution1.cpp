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
    static constexpr int inf = 0x3f3f3f3f;
    int res;
    struct SubTree {
        bool isBST;
        int minValue;
        int maxValue;
        int sumValue;
        SubTree(bool isBST, int minValue, int maxValue, int sumValue) : isBST(isBST), minValue(minValue), maxValue(maxValue), sumValue(sumValue) {}
    };

    SubTree dfs(TreeNode* root) {
        if (root == nullptr) {
            return SubTree(true, inf, -inf, 0);
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.isBST && right.isBST &&
                root->val > left.maxValue && 
                root->val < right.minValue) {
            int sum = root->val + left.sumValue + right.sumValue;
            res = max(res, sum);
            return SubTree(true, min(left.minValue, root->val), 
                           max(root->val, right.maxValue), sum);
        } else {
            return SubTree(false, 0, 0, 0);
        }
    }

    int maxSumBST(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};
