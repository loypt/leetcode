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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> fa;
        TreeNode* s = nullptr;
        TreeNode* t = nullptr;
        
        function<void(TreeNode*)> dfs = [&](TreeNode* curr) {
            if (curr->val == startValue) {
                s = curr;
            }
            if (curr->val == destValue) {
                t = curr;
            }
            if (curr->left) {
                fa[curr->left] = curr;
                dfs(curr->left);
            }
            if (curr->right) {
                fa[curr->right] = curr;
                dfs(curr->right);
            }
        };
        
        dfs(root);
        
        function<string(TreeNode*)> path = [&](TreeNode* curr) {
            string res;
            while (curr != root) {
                TreeNode* par = fa[curr];
                if (curr == par->left) {
                    res.push_back('L');
                }
                else {
                    res.push_back('R');
                }
                curr = par;
            }
            reverse(res.begin(), res.end());
            return res;
        };
        
        string path1 = path(s);
        string path2 = path(t);
        int l1 = path1.size(), l2 = path2.size();
        int i = 0;
        while (i < min(l1, l2)) {
            if (path1[i] == path2[i]) {
                ++i;
            }
            else {
                break;
            }
        }
        string finalpath(l1 - i, 'U');
        finalpath.append(path2.substr(i, l2 - i));
        return finalpath;
    }
};
