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
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inOrder(root, nums);
        pair<int, int> swapped = findTwoSwapped(nums);
        recover(root, 2, swapped.first, swapped.second);
    }

    void inOrder(TreeNode* root, vector<int>& nums){
        if(root == nullptr){
            return;
        }
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }

    pair<int, int> findTwoSwapped(vector<int>& nums){
        int n = nums.size();
        int index1 = -1, index2 = -1;
        for(int i = 0; i < n-1; ++i){
            if(nums[i+1] < nums[i]){
                index2 = i+1;
                if(index1 == -1){
                    index1 = i;
                }else{
                    break;
                }
            }
        }
        int x = nums[index1], y = nums[index2];
        return {x, y};
    }

    void recover(TreeNode* r, int count, int x, int y){
        if(r != nullptr){
            if(r->val == x || r->val == y){
                r ->val = r->val == x ? y : x;
                if(--count == 0){
                    return;
                }
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
    }

};
