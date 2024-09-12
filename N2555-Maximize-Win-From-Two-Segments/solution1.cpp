class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = lower_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] - k) - prizePositions.begin();
            ans = max(ans, i - x + 1 + dp[x]);
            dp[i + 1] = max(dp[i], i - x + 1);
        }
        return ans;
    }
};
