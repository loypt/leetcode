class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(51, 0));
        int mod = 1e9 + 7;

        for (int v = 0; v <= nums[0]; ++v) {
            dp[0][v] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int v2 = 0; v2 <= nums[i]; ++v2) {
                for (int v1 = 0; v1 <= v2; ++v1) {
                    if (nums[i - 1] - v1 >= nums[i] - v2) {
                        dp[i][v2] = (dp[i][v2] + dp[i - 1][v1]) % mod;
                    }
                }
            }
        }

        int res = 0;
        for (int v : dp[n - 1]) {
            res = (res + v) % mod;
        }
        return res;
    }
};
