class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int mod = 1e9 + 7;
        int len = nextVisit.size();
        vector<int> dp(len);

        dp[0] = 2;
        for (int i = 1; i < len; i++) {
            int to = nextVisit[i];
            dp[i] = 2 + dp[i - 1];
            
            if (to != 0) {
                dp[i] = (dp[i] - dp[to - 1] + mod) % mod;
            }
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        return dp[len - 2];
    }
};
