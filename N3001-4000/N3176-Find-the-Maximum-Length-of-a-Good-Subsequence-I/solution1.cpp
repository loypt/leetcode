class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int len = nums.size();
        vector<vector<int>> dp;
        dp.resize(len, vector<int>(51, -1));

        for (int i = 0; i < len; i++) {
            dp[i][0] = 1;
            for (int l = 0; l <= k; l++) {
                for (int j = 0; j < i; j++) {
                    int add = (nums[i] != nums[j]);
                    if (l - add >= 0 && dp[j][l - add] != -1) {
                        dp[i][l] = max(dp[i][l], dp[j][l - add] + 1);
                    }
                }
                ans = max(ans, dp[i][l]);
            }
        }

        return ans;
    }
};
