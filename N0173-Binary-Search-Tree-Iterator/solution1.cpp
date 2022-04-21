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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : idx(0), arr(inOrderTraversal(root)) {}
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return idx < arr.size();
    }
    
private:
    vector<int> arr;
    int idx;

    vector<int> inOrderTraversal(TreeNode* root){
        vector<int> res;
        inOrder(root, res);
        return res;
    }


    void inOrder(TreeNode* root, vector<int>& res){
        if(!root){
            return;
        }
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
