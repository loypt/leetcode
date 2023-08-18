class Solution {
public:
    int calculate(const vector<int>& slices) {
        int N = slices.size(), n = (N + 1) / 3;
        vector<vector<int>> dp(N, vector<int>(n + 1, INT_MIN));
        dp[0][0] = 0;
        dp[0][1] = slices[0];
        dp[1][0] = 0;
        dp[1][1] = max(slices[0], slices[1]);
        for (int i = 2; i < N; i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i]);
            }
        }
        return dp[N - 1][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        vector<int> v1(slices.begin() + 1, slices.end());
        vector<int> v2(slices.begin(), slices.end() - 1);
        int ans1 = calculate(v1);
        int ans2 = calculate(v2);
        return max(ans1, ans2);
    }
};
