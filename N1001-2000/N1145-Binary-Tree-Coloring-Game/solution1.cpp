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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* xNode = find(root, x);
        int leftSize = getSubtreeSize(xNode->left);
        if (leftSize >= (n + 1) / 2) {
            return true;
        }
        int rightSize = getSubtreeSize(xNode->right);
        if (rightSize >= (n + 1) / 2) {
            return true;
        }
        int remain = n - 1 - leftSize - rightSize;
        return remain >= (n + 1) / 2;
    }

    TreeNode* find(TreeNode *node, int x) {
        if (node == NULL) {
            return NULL;
        }
        if (node->val == x) {
            return node;
        }
        TreeNode* res = find(node->left, x);
        if (res != NULL) {
            return res;
        } else {
            return find(node->right, x);
        }
    }

    int getSubtreeSize(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }
};
