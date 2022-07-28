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
    void flatten(TreeNode* root) {
        auto v = vector<TreeNode*>();
        auto stk = stack<TreeNode*>();
        TreeNode *node = root;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                v.push_back(node);
                stk.push(node);
                node = node->left;
            }
            node = stk.top(); stk.pop();
            node = node->right;
        }
        int size = v.size();
        for (int i = 1; i < size; i++) {
            auto prev = v.at(i - 1), curr = v.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }
};
