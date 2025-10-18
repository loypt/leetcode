class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD = 1e9 + 7;

        vector<int> dp(5);
        dp[0] = dp[1] = 1;

        int cnt = 1;
        for (int i = 1; i < pressedKeys.size(); ++i) {
            if (pressedKeys[i] == pressedKeys[i - 1]) ++cnt;
            else cnt = 1;
            int len = min(cnt, pressedKeys[i] == '7' || pressedKeys[i] == '9' ? 4 : 3);
            int ii = (i + 1) % 5;
            dp[ii] = dp[(ii - 1 + 5) % 5];
            for (int j = 2; j <= len; ++j) {
                dp[ii] = (dp[ii] + dp[(ii - j + 5) % 5]) % MOD;
            }
        }
        return dp[pressedKeys.size() % 5];
    }
};
