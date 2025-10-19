class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if ((nums[i] ^ nums[i - 1]) & 1) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        
        vector<bool> res;
        for (auto &q : queries) {
            int x = q[0], y = q[1];
            res.emplace_back(dp[y] >= y - x + 1);
        }
        return res;
    }
};
