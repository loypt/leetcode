class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        vector<int> dp(1 << m, 0);
        vector<vector<int>> gcd_tmp(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                gcd_tmp[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int all = 1 << m;
        for (int s = 1; s < all; ++s) {
            int t = __builtin_popcount(s);
            if (t & 1) {
                continue;
            }
            for (int i = 0; i < m; ++i) {
                if ((s >> i) & 1) {
                    for (int j = i + 1; j < m; ++j) {
                        if ((s >> j) & 1) {
                            dp[s] = max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + t / 2 * gcd_tmp[i][j]);
                        }
                    }
                }
            }
        }
        return dp[all - 1];
    }
};
