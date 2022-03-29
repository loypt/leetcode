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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i = 0; i < inorder.size(); ++i){
            dic[inorder[i]] = i;
        }
        return recur(0, 0, inorder.size()-1);
    }
private:
    vector<int> preorder;
    unordered_map<int, int> dic;
    TreeNode* recur(int root, int left, int right){
        i(left > right) return nullptr;
        TreeNode* node = new TreeNode(preorder[root]);
        int i = dic[preorder[root]];
        node->left = recur(root+1, left, i-1);
        node->right = recur(root+i-left +1, i+1, right);
        return node;
    }
};
