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
    TreeNode* clone(TreeNode* root) {
    TreeNode* new_root = new TreeNode(0);
    new_root->left = (root->left) ? clone(root->left) : nullptr;
    new_root->right = (root->right) ? clone(root->right) : nullptr; 
    return new_root;
  } 

  vector<TreeNode*> allPossibleFBT(int n) {
    std::vector<TreeNode*> ret;
    if (1 == n) {
      ret.emplace_back(new TreeNode(0));
    } else if (n % 2) {
      for (int i = 2; i <= n; i += 2) {
        auto left = allPossibleFBT(i - 1);
        auto right = allPossibleFBT(n - i);
        for (int l_idx = 0; l_idx < left.size(); ++l_idx) {
          for (int r_idx = 0; r_idx < right.size(); ++r_idx) {
            ret.emplace_back(new TreeNode(0));
            ret.back()->left = (r_idx == right.size() - 1) ? left[l_idx] : clone(left[l_idx]);
            ret.back()->right = (l_idx == left.size() - 1) ? right[r_idx] : clone(right[r_idx]);
          }
        }
      }
    }
    return ret;
  }
};
