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
    int check(vector<int>&v){
        vector<int>v1(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        map<int,int>m;
        int n = v1.size();
        for(int i=0;i<n;i++){
            m[v1[i]] = i;
        }
        int swaps = 0,i=0;
        while(i<n){
            int index = m[v[i]];
            if(index==i) i++;
            else{
                int temp = v[i];
                v[i] = v[index];
                v[index] = temp;
                swaps++; 
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int ans =0;
        while(!q.empty()){
            vector<int>v;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            ans += check(v);
        }
        return ans;
    }
};
