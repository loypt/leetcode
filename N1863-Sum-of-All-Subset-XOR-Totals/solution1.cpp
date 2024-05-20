class Solution {
public:
    int res;
    int n;
    
    void dfs(int val, int idx, vector<int>& nums){
        if (idx == n){
            res += val;
            return;
        }
        dfs(val ^ nums[idx], idx + 1, nums);
        dfs(val, idx + 1, nums);
    }
    
    int subsetXORSum(vector<int>& nums) {
        res = 0;
        n = nums.size();
        dfs(0, 0, nums);
        return res;
    }
};
